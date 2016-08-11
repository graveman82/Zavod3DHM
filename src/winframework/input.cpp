/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "winframework/input.h"
#include "z3DLib/debugsys.h"

namespace z3D{
//-----------------------------------------------------------------------------
InputVirtualKeyMapWin::InputVirtualKeyMapWin(){
    vkeyMap_['A'] = KBRD_DEV_BTN_A;
    vkeyMap_['B'] = KBRD_DEV_BTN_B;
    vkeyMap_['C'] = KBRD_DEV_BTN_C;
    vkeyMap_['D'] = KBRD_DEV_BTN_D;
    vkeyMap_['E'] = KBRD_DEV_BTN_E;
    vkeyMap_['F'] = KBRD_DEV_BTN_F;
    vkeyMap_['G'] = KBRD_DEV_BTN_G;
    vkeyMap_['H'] = KBRD_DEV_BTN_H;
    vkeyMap_['I'] = KBRD_DEV_BTN_I;
    vkeyMap_['J'] = KBRD_DEV_BTN_J;
    vkeyMap_['K'] = KBRD_DEV_BTN_K;
    vkeyMap_['L'] = KBRD_DEV_BTN_L;
    vkeyMap_['M'] = KBRD_DEV_BTN_M;
    vkeyMap_['N'] = KBRD_DEV_BTN_N;
    vkeyMap_['O'] = KBRD_DEV_BTN_O;
    vkeyMap_['P'] = KBRD_DEV_BTN_P;
    vkeyMap_['Q'] = KBRD_DEV_BTN_Q;
    vkeyMap_['R'] = KBRD_DEV_BTN_R;
    vkeyMap_['S'] = KBRD_DEV_BTN_S;
    vkeyMap_['T'] = KBRD_DEV_BTN_T;
    vkeyMap_['U'] = KBRD_DEV_BTN_U;
    vkeyMap_['V'] = KBRD_DEV_BTN_V;
    vkeyMap_['W'] = KBRD_DEV_BTN_W;
    vkeyMap_['X'] = KBRD_DEV_BTN_X;
    vkeyMap_['Y'] = KBRD_DEV_BTN_Y;
    vkeyMap_['Z'] = KBRD_DEV_BTN_Z;
    vkeyMap_[VK_ESCAPE] = KBRD_DEV_BTN_ESC;
    vkeyMap_[VK_RETURN] = KBRD_DEV_BTN_ENTER;
}
//-----------------------------------------------------------------------------
InputDeviceButtonId InputVirtualKeyMapWin::ConvertKey(int vkey) {
    VKeyMapIter iter = vkeyMap_.find(vkey);
    if (iter == vkeyMap_.end()) return INPUT_DEV_BTN_UNDEFINED;
    return iter->second;
}
//-----------------------------------------------------------------------------
InputVirtualKeyMapWin::~InputVirtualKeyMapWin() { vkeyMap_.clear(); }
//-----------------------------------------------------------------------------
inline void InputDevice::HandleButtonEvent(InputDeviceButtonId btnId, bool fPressed){
    SetButtonNextState(btnId, fPressed);
}
//-----------------------------------------------------------------------------
inline int InputDeviceKeyboard::GetButtonIndex(InputDeviceButtonId btnId){
    return btnId - KBRD_DEV_BTN_BEGIN;
}
//-----------------------------------------------------------------------------
void InputDeviceKeyboard::SetButtonNextState(InputDeviceButtonId btnId, bool fPressed){
    keyStateBuffers_[btnId].stateNext_.fPressed_ = fPressed;
    keyStateBuffers_[btnId].fStateNext_ = true;
}
//-----------------------------------------------------------------------------
InputDeviceKeyboard::~InputDeviceKeyboard() {}
//-----------------------------------------------------------------------------
inline bool InputDeviceKeyboard::GetButtonPrevState(InputDeviceButtonId btnId){
    return keyStateBuffers_[GetButtonIndex(btnId)].statePrev_.fPressed_;
}
//-----------------------------------------------------------------------------
inline bool InputDeviceKeyboard::GetButtonCurState(InputDeviceButtonId btnId){
    return keyStateBuffers_[GetButtonIndex(btnId)].stateCur_.fPressed_;
}
//-----------------------------------------------------------------------------
void InputDeviceKeyboard::HandleWindowMessage(MSG& msg){
    bool fPressed = false;
    int vkey;
    switch (msg.message)
    {
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        fPressed = true;
        vkey = (int)msg.wParam;
        break;
    case WM_KEYUP:
    case WM_SYSKEYUP:
        fPressed = false;
        vkey = (int)msg.wParam;
        break;
    default: // необрабатываемое сообщение
        return;
    }
    InputDeviceButtonId btnId = vkeyMap_.ConvertKey(vkey);
    HandleButtonEvent(btnId, fPressed);
}
//-----------------------------------------------------------------------------
void InputDeviceKeyboard::Update(){
    for (int i = (int)KBRD_DEV_BTN_BEGIN; i < (int)KBRD_DEV_BTN_END; i++){
        InputDeviceButtonId id = (InputDeviceButtonId)i;
        keyStateBuffers_[GetButtonIndex(id)].statePrev_ = keyStateBuffers_[GetButtonIndex(id)].stateCur_;
        if (keyStateBuffers_[GetButtonIndex(id)].fStateNext_){
            keyStateBuffers_[GetButtonIndex(id)].stateCur_ = keyStateBuffers_[GetButtonIndex(id)].stateNext_;
            keyStateBuffers_[GetButtonIndex(id)].fStateNext_ = false;
        }
    }
}
//-----------------------------------------------------------------------------
InputManager::InputManager(){
    deviceMap_[INPUT_DEV_KEYBOARD] = new InputDeviceKeyboard;
    //deviceMap_[INPUT_DEV_MOUSE] = new InputDeviceMouse;
}
//-----------------------------------------------------------------------------
InputManager::~InputManager(){
    delete deviceMap_[INPUT_DEV_KEYBOARD];
    //delete deviceMap_[INPUT_DEV_MOUSE];
    deviceMap_.clear();
}
//-----------------------------------------------------------------------------
InputDevice* InputManager::GetDevice(InputDeviceId deviceId){
    DeviceMapIter iter = deviceMap_.find(deviceId);
    if (iter == deviceMap_.end()) return 0;
    return iter->second;
}
//-----------------------------------------------------------------------------
void InputManager::HandleWindowMessage(MSG& msg){
    for (DeviceMapIter iter = deviceMap_.begin(), end = deviceMap_.end(); iter != end; ++iter){
        iter->second->HandleWindowMessage(msg);
    }
}
//-----------------------------------------------------------------------------
void InputManager::Update(){
    for (DeviceMapIter iter = deviceMap_.begin(), end = deviceMap_.end(); iter != end; ++iter){
        iter->second->Update();
    }
}
//-----------------------------------------------------------------------------
InputMap::InputMap(InputManager* inputMng) :
    inputMng_(inputMng){
    Z3D_ASSERT_HIGH(inputMng != 0, "inputMng must be no null", true);
}
//-----------------------------------------------------------------------------
void InputMap::Map(int userBtnId, InputDeviceButtonId devBtnId, InputDeviceId deviceId){
    UserBtnMapIter iter = userBtnMap_.find(userBtnId);
    if (iter != userBtnMap_.end()){
        DeviceIdButtonIdVec& v = iter->second;
        for (DeviceIdButtonIdVecIter iter = v.begin(), iterEnd = v.end(); iter != iterEnd; ++iter){
            if (iter->deviceId_ == deviceId && iter->btnId_ == devBtnId)
                return;
        }
        v.push_back(DeviceIdButtonId(deviceId, devBtnId));
        return;
    }else{
        userBtnMap_[userBtnId] = DeviceIdButtonIdVec();
        userBtnMap_[userBtnId].push_back(DeviceIdButtonId(deviceId, devBtnId));
        return;
    }
}
//-----------------------------------------------------------------------------
void InputMap::Unmap(int userBtnId, InputDeviceButtonId devBtnId, InputDeviceId deviceId){
    UserBtnMapIter iter = userBtnMap_.find(userBtnId);
    if (iter != userBtnMap_.end()){
        DeviceIdButtonIdVec& v = iter->second;
        for (DeviceIdButtonIdVecIter iter = v.begin(), iterEnd = v.end(); iter != iterEnd; ++iter){
            if (iter->deviceId_ == deviceId && iter->btnId_ == devBtnId){
                v.erase(iter);
                return;
            }
        }
    }
}
//-----------------------------------------------------------------------------
bool InputMap::IsPressed(int userBtnId){
    UserBtnMapIter iter = userBtnMap_.find(userBtnId);
    if (iter != userBtnMap_.end()){
        DeviceIdButtonIdVec& v = iter->second;
        for (DeviceIdButtonIdVecIter iter = v.begin(), iterEnd = v.end(); iter != iterEnd; ++iter){
            InputDevice* device = inputMng_->GetDevice(iter->deviceId_);
            Z3D_ASSERT_HIGH (device != 0, "null device ptr", true);
            return device->GetButtonCurState(iter->btnId_);
        }
    }
    return false;
}
//-----------------------------------------------------------------------------
bool InputMap::IsNewlyPressed(int userBtnId){
    UserBtnMapIter iter = userBtnMap_.find(userBtnId);
    if (iter != userBtnMap_.end()){
        DeviceIdButtonIdVec& v = iter->second;
        for (DeviceIdButtonIdVecIter iter = v.begin(), iterEnd = v.end(); iter != iterEnd; ++iter){
            InputDevice* device = inputMng_->GetDevice(iter->deviceId_);
            Z3D_ASSERT_HIGH (device != 0, "null device ptr", true);
            if (device->GetButtonCurState(iter->btnId_))
                if (!device->GetButtonPrevState(iter->btnId_))
                    return true;
        }
    }
    return false;
}
//-----------------------------------------------------------------------------
} // end of z3D
