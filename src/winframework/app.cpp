/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/


#include "winframework/app.h"
#include "z3dlib/debugsys.h"

//-----------------------------------------------------------------------------
/** Входная точка проекта */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR szCmdLine, int iCmdShow){
    z3D::WindowsSpecParams params (hInstance, szCmdLine, iCmdShow);
    z3D::IProject* proj = Z3D_NewProject();
    z3D::App* app = new z3D::App(&params);
    app->Run(proj);
    delete app;
    Z3D_DeleteProject(proj);
    return 0;
}
//-----------------------------------------------------------------------------
namespace z3D{
IProject::IProject() :
    title_(0),
    windowWidth_(640),
    windowHeight_(480),
    fpsMax_(60.0f)
{}
//-----------------------------------------------------------------------------
void IProject::LimitFrameRate(){
	// измеряем время, прошедшее с предыдущего обновления
	static int timeLast = ::timeGetTime();
	int timeCur = ::timeGetTime();
	int timeDelta = (timeCur - timeLast);

	// ограничить макимальный фреймрейт
	int timeDesiredDelta = 1000.0f / fpsMax_;
	if (timeDelta < timeDesiredDelta)
		::Sleep( (timeDesiredDelta - timeDelta));

	timeLast = ::timeGetTime();
}
//-----------------------------------------------------------------------------
App* App::instance_ = 0;
//-----------------------------------------------------------------------------
App* App::GetInstance() { return instance_; }
//-----------------------------------------------------------------------------
App::App(const WindowsSpecParams* params) :
    proj_(0), state_(kAppNotInited),
    winSpecParams_((params != 0) ? params->hInstance_ : ::GetModuleHandle(0),
        (params != 0) ? params->szCmdLine_ : 0,
        (params != 0) ? params->iCmdShow_ : SW_SHOWNORMAL),
    hWnd_(0),
    inputMng_(0){
    instance_ = this;
}
//-----------------------------------------------------------------------------
BOOL App::Run(IProject* proj){
    if (proj == 0){
        return FALSE;
    }
    proj_ = proj;
    if (!Initialize()){
        return FALSE;
    }
    EnterLoop();
    Clear();
    return TRUE;
}
//-----------------------------------------------------------------------------
BOOL App::Initialize(){
    proj_->Configuration();
    if (!CreateMainWindow()){
        Z3D_ERROR(DebugTool::kError, 0, "Create main window failed", true);
        return FALSE;
    }
    inputMng_ = new InputManager();
    if (!proj_->Initialize()){
        return FALSE;
    }
    state_ = kAppInited;
    Log("Application was initialized successfully.\n");
    return TRUE;
}
//-----------------------------------------------------------------------------
void App::Terminate(){
    state_ = kAppTerminating;
    Clear();
}
//-----------------------------------------------------------------------------
void App::EnterLoop(){
    MSG msg;
    // Приложение может войти сюда только один раз - после инициализации
    if (state_ != kAppInited){
        return;
    }
    state_ = kAppInLoop;
    while(state_ != kAppTerminating){
        Z3D_ASSERT_HIGH(inputMng_ != 0, "input manager must exist at this moment", true);
        inputMng_->Update();
        while(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
            if(msg.message == WM_QUIT){
                state_ = kAppTerminating;
                break; // более не обрабатываем сообщения
            }
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            inputMng_->HandleWindowMessage(msg);
        }
        // Если статус приложения изменился на "Завершение" во время обработки сообщений,
        // то ничего не делаем
        if (state_ != kAppTerminating){
            proj_->Frame();
            proj_->LimitFrameRate();
        }
    }
    // После выхода из цикла приложение становится ненужным, завершаем его.
    Terminate();
}
//-----------------------------------------------------------------------------
void App::Clear(){
    if (inputMng_ != 0){
        delete inputMng_;
        inputMng_ = 0;
    }
}
//-----------------------------------------------------------------------------
LRESULT CALLBACK App::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch ( message ){
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;
    default:
        return ::DefWindowProc (hWnd, message, wParam, lParam);
    }
    return 0;
}
//-----------------------------------------------------------------------------
BOOL App::CreateMainWindow(){
    if (proj_->Title() == 0) {
        return FALSE;
    }
    WNDCLASSEX wce;
    wce.cbSize = sizeof (WNDCLASSEX);
    wce.hInstance = winSpecParams_.hInstance_;
    wce.lpszClassName = proj_->Title();
    wce.lpfnWndProc = StaticWndProc;
    wce.style = CS_HREDRAW | CS_VREDRAW;
    wce.hIcon = ::LoadIcon (0, IDI_APPLICATION);
    wce.hIconSm = ::LoadIcon (0, IDI_APPLICATION);
    wce.hCursor = ::LoadCursor (0, IDC_ARROW);
    wce.lpszMenuName = 0;
    wce.cbClsExtra = 0;
    wce.cbWndExtra = 0;
    wce.hbrBackground = (HBRUSH) COLOR_WINDOW;
    if (!::RegisterClassEx (&wce)) {
        return FALSE;
    }
    hWnd_ = ::CreateWindowEx (0, proj_->Title(), proj_->Title(), WS_OVERLAPPEDWINDOW,
        0, 0, proj_->WindowWidth(), proj_->WindowHeight(),
        0, 0, winSpecParams_.hInstance_, 0);
    if (hWnd_ == 0){
        return FALSE;
    }
    ::ShowWindow (hWnd_, winSpecParams_.iCmdShow_);
    ::UpdateWindow(hWnd_);
    return TRUE;
}
//-----------------------------------------------------------------------------
InputManager* App::GetInputManager(){
    return inputMng_;
}
//-----------------------------------------------------------------------------
} // end of z3D

