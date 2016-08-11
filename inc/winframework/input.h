#ifndef WINFRAMEWORK_INPUT_H_
#define WINFRAMEWORK_INPUT_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include <vector>
#include <map>
#include <windows.h>

namespace z3D{
//-----------------------------------------------------------------------------
/// Идентификаторы устройств ввода
enum InputDeviceId{
    INPUT_DEV_UNDEFINED = -1,
    INPUT_DEV_KEYBOARD, ///< идентификатор клавиатуры
    INPUT_DEV_MOUSE     ///< идентификатор мыши
};
//-----------------------------------------------------------------------------
/// Идентификаторы кнопок устройств ввода
enum InputDeviceButtonId{
    INPUT_DEV_BTN_UNDEFINED = -1,           ///< неопределенная кнопка
    KBRD_DEV_BTN_BEGIN,
    KBRD_DEV_BTN_A = KBRD_DEV_BTN_BEGIN,    ///< Клавиша A
    KBRD_DEV_BTN_B,                         ///< Клавиша B
    KBRD_DEV_BTN_C,                         ///< Клавиша C
    KBRD_DEV_BTN_D,                         ///< Клавиша D
    KBRD_DEV_BTN_E,                         ///< Клавиша E
    KBRD_DEV_BTN_F,                         ///< Клавиша F
    KBRD_DEV_BTN_G,                         ///< Клавиша G
    KBRD_DEV_BTN_H,                         ///< Клавиша H
    KBRD_DEV_BTN_I,                         ///< Клавиша I
    KBRD_DEV_BTN_J,                         ///< Клавиша J
    KBRD_DEV_BTN_K,                         ///< Клавиша K
    KBRD_DEV_BTN_L,                         ///< Клавиша L
    KBRD_DEV_BTN_M,                         ///< Клавиша M
    KBRD_DEV_BTN_N,                         ///< Клавиша N
    KBRD_DEV_BTN_O,                         ///< Клавиша O
    KBRD_DEV_BTN_P,                         ///< Клавиша P
    KBRD_DEV_BTN_Q,                         ///< Клавиша Q
    KBRD_DEV_BTN_R,                         ///< Клавиша R
    KBRD_DEV_BTN_S,                         ///< Клавиша S
    KBRD_DEV_BTN_T,                         ///< Клавиша T
    KBRD_DEV_BTN_U,                         ///< Клавиша U
    KBRD_DEV_BTN_V,                         ///< Клавиша V
    KBRD_DEV_BTN_W,                         ///< Клавиша W
    KBRD_DEV_BTN_X,                         ///< Клавиша X
    KBRD_DEV_BTN_Y,                         ///< Клавиша Y
    KBRD_DEV_BTN_Z,                         ///< Клавиша Z
    KBRD_DEV_BTN_ESC,                       ///< Клавиша Escape
    KBRD_DEV_BTN_ENTER,                     ///< Клавиша Enter
    KBRD_DEV_BTN_END,                       ///< Количество идентификаторов клавиш клавиатуры
    MOUSE_DEV_BTN_BEGIN,
    MOUSE_DEV_BTN_LEFT = MOUSE_DEV_BTN_BEGIN,
    MOUSE_DEV_BTN_RIGHT,
    MOUSE_DEV_BTN_END
};
//-----------------------------------------------------------------------------
/// Состояние кнопки устройства ввода
class InputDeviceButtonState{
public:
    bool fPressed_;     ///< флаг (true - "нажата", false - "не нажата")

    InputDeviceButtonState() : fPressed_(false){}
};
//-----------------------------------------------------------------------------
/// Буфер состояний кнопки устройства ввода
class InputDeviceButtonStateBuffer{
public:
    InputDeviceButtonState stateCur_;       ///< текущее состояние
    InputDeviceButtonState statePrev_;      ///< предыдущее состояние
    InputDeviceButtonState stateNext_;      ///< будущее состояние
    bool fStateNext_;                       ///< наличие будущего состояния

    InputDeviceButtonStateBuffer() : fStateNext_(false){}
};
//-----------------------------------------------------------------------------
/// Карта клавиш. Отображает виртуальные клавиши в идентификаторы кнопок устройств ввода InputDeviceButtonId.
class InputVirtualKeyMapWin{
    typedef std::map<int, InputDeviceButtonId> VKeyMap;
    typedef VKeyMap::iterator VKeyMapIter;
    VKeyMap vkeyMap_;
public:
    /// Кон-р.
    InputVirtualKeyMapWin();
    ~InputVirtualKeyMapWin();
    /// Конвертирует виртуальную клавишу в тип InputDeviceButtonId.
    InputDeviceButtonId ConvertKey(int vkey);
};
//-----------------------------------------------------------------------------
/// Интерфейс устройства ввода.
class InputDevice{
protected:
    virtual int GetButtonIndex(InputDeviceButtonId btnId) = 0;
    virtual void SetButtonNextState(InputDeviceButtonId btnId, bool fPressed) = 0;
	void HandleButtonEvent(InputDeviceButtonId btnId, bool fPressed);
public:
    virtual ~InputDevice(){}

    virtual bool GetButtonPrevState(InputDeviceButtonId btnId) = 0;
	virtual bool GetButtonCurState(InputDeviceButtonId btnId) = 0;

	virtual void HandleWindowMessage(MSG& msg) = 0;
	virtual void Update() = 0;
};
//-----------------------------------------------------------------------------
/// Утройство ввода клавиатура.
class InputDeviceKeyboard : public InputDevice{
    InputDeviceButtonStateBuffer keyStateBuffers_[KBRD_DEV_BTN_END - KBRD_DEV_BTN_BEGIN];
    InputVirtualKeyMapWin vkeyMap_;

    int GetButtonIndex(InputDeviceButtonId btnId);
    void SetButtonNextState(InputDeviceButtonId btnId, bool fPressed);

public:
    virtual ~InputDeviceKeyboard();

    bool GetButtonPrevState(InputDeviceButtonId btnId);
    bool GetButtonCurState(InputDeviceButtonId btnId);

	void HandleWindowMessage(MSG& msg);
	void Update();
};
//-----------------------------------------------------------------------------
/// Утройство ввода мышь.
class InputDeviceMouse : public InputDevice{
    InputDeviceButtonStateBuffer keyStateBuffers_[MOUSE_DEV_BTN_END - MOUSE_DEV_BTN_BEGIN];
    InputVirtualKeyMapWin vkeyMap_;

    void SetButtonNextState(InputDeviceButtonId btnId, bool fPressed);

public:
    int GetButtonIndex(InputDeviceButtonId btnId);
	void HandleWindowMessage(MSG& msg);
	void Update();
	bool GetButtonCurState(InputDeviceButtonId btnId);
};
//-----------------------------------------------------------------------------
/// Менеджер ввода.
class InputManager{
    typedef std::map<InputDeviceId, InputDevice*> DeviceMap;
    typedef DeviceMap::iterator DeviceMapIter;
    DeviceMap deviceMap_;

    InputManager(const InputManager&);
    InputManager& operator=(const InputManager&);

public:
    InputManager();
    ~InputManager();
    InputDevice* GetDevice(InputDeviceId deviceId);
    void HandleWindowMessage(MSG& msg);
    void Update();
};
//-----------------------------------------------------------------------------
/// Карта ввода - отображает пользовательские идентификаторы в идентификаторы кнопок устройств ввода.
class InputMap{
    // Пара: идентификатор устройства ввода - идентификатор кнопки устройства ввода
    struct DeviceIdButtonId{
        InputDeviceId deviceId_;
        InputDeviceButtonId btnId_;

        DeviceIdButtonId() :
            deviceId_(INPUT_DEV_UNDEFINED),
            btnId_(INPUT_DEV_BTN_UNDEFINED) {}
        DeviceIdButtonId(InputDeviceId deviceId,
                         InputDeviceButtonId btnId) :
                         deviceId_(deviceId),
                         btnId_(btnId) {}
    };
    typedef std::vector<DeviceIdButtonId> DeviceIdButtonIdVec;
    typedef DeviceIdButtonIdVec::iterator DeviceIdButtonIdVecIter;
    typedef std::map<int, DeviceIdButtonIdVec> UserBtnMap;
    typedef UserBtnMap::iterator UserBtnMapIter;

    InputManager* inputMng_;
    UserBtnMap userBtnMap_;

public:
    InputMap(InputManager* inputMng);
    void Map(int userBtnId, InputDeviceButtonId devBtnId, InputDeviceId deviceId);
    void Unmap(int userBtnId, InputDeviceButtonId devBtnId, InputDeviceId deviceId);
    bool IsPressed(int userBtnId);
    bool IsNewlyPressed(int userBtnId);
};
//-----------------------------------------------------------------------------
} // end of z3D

#endif // WINFRAMEWORK_INPUT_H_

