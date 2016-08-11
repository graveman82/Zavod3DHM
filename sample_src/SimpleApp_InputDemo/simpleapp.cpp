/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "winframework/app.h"
#include "z3DLib/debugsys.h"

//-----------------------------------------------------------------------------
enum CustomKeys{
    WhatAreF,
    MoveForward
};
//-----------------------------------------------------------------------------
/// Класс проекта
class DemoProject : public z3D::IProject{
    z3D::InputMap* inputMap_;
public:
    DemoProject() :
        inputMap_(0){
    }
    virtual ~DemoProject() {
        Clear();
    }

    void Configuration(){
        SetTitle("MyProject");
        SetWindowWidth(200);
        SetWindowHeight(300);
    }

    BOOL Initialize() {
        inputMap_ = new z3D::InputMap(z3D::App::GetInstance()->GetInputManager());
        inputMap_->Map(WhatAreF, z3D::KBRD_DEV_BTN_F, z3D::INPUT_DEV_KEYBOARD);
        inputMap_->Map(MoveForward, z3D::KBRD_DEV_BTN_W, z3D::INPUT_DEV_KEYBOARD);
        return TRUE;
    }

    void Frame(){
        static int cWhatAreFPress = 0;
        if (inputMap_->IsNewlyPressed(WhatAreF)){
            z3D::Log("Dude[%d] say: \"Whar are f..., m-a-a-a-n?!\"\n", cWhatAreFPress++);
        }
        static int cMoveForwardPress = 0;
        if (inputMap_->IsNewlyPressed(MoveForward)){
            z3D::Log("Move forward key pressed (%d) time\n", ++cMoveForwardPress);
        }
    }

    void Clear(){
        if (inputMap_ != 0){
            delete inputMap_;
            inputMap_ = 0;
        }
    }
};
//-----------------------------------------------------------------------------
z3D::IProject* Z3D_NewProject() { return new DemoProject(); }
//-----------------------------------------------------------------------------
void Z3D_DeleteProject(z3D::IProject* project) { delete project; }
//-----------------------------------------------------------------------------
