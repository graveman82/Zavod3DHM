#ifndef WINFRAMEWORK_APP_H
#define WINFRAMEWORK_APP_H

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include <windows.h>

namespace z3D{
//-----------------------------------------------------------------------------
/// Интерфейс проекта
class IProject{
    const char* title_;     ///< название проекта
    UINT windowWidth_;      ///< ширина окна, необходимая для проекта
    UINT windowHeight_;     ///< высота окна, необходимая для проекта
    float fpsMax_;          ///< максимальный фреймрейт (60 кадров/сек по умолчанию)
public:
    IProject();
    virtual ~IProject() {}
    /// Конфигурация.
    virtual void Configuration() = 0;
    /// Инициализация.
    virtual BOOL Initialize() = 0;
    /// Покадровая функция.
    virtual void Frame() = 0;
    /// Очистка данных, освобождение ресурсов.
    virtual void Clear() = 0;
    /// Ограничить число кадров в секунду.
    void LimitFrameRate();
    /// Возвратить строку с названием проекта.
    const char* Title() const { return title_; }
    /// Задать строку с названием проекта.
    void SetTitle(const char* title) { title_ = title; }
    /// Возвратить значение ширины, необходимой для окна проекта.
    UINT WindowWidth() const { return windowWidth_; }
    /// Задать значение ширины, необходимой для окна проекта.
    void SetWindowWidth(UINT windowWidth) { windowWidth_ = windowWidth; }
    /// Возвратить значение высоты, необходимой для окна проекта.
    UINT WindowHeight() const { return windowHeight_; }
    /// Задать значение высоты, необходимой для окна проекта.
    void SetWindowHeight(UINT windowHeight) { windowHeight_ = windowHeight; }
};
//-----------------------------------------------------------------------------
/// параметры, специфичные для Windows-приложения
struct WindowsSpecParams {
    HINSTANCE hInstance_;   ///< дескриптор приложения
    LPTSTR szCmdLine_;      ///< командная строка
    int iCmdShow_;          ///< флаг отображения окна
    WindowsSpecParams(HINSTANCE hInstance, LPTSTR szCmdLine, int iCmdShow) :
        hInstance_(hInstance), szCmdLine_(szCmdLine), iCmdShow_(iCmdShow){
    }
};
//-----------------------------------------------------------------------------
/** @class класс приложения
    @note синглтон */
class App{
    /// состояния приложения
    enum eState{
        kAppNotInited,      ///< приложение не инициализировано
        kAppInited,         ///< приложение инициализировано (готово к запуску цикла)
        kAppInLoop,         ///< приложение находится в цикле
        kAppTerminating     ///< приложение выполняет свое завершение
    };
    static App* instance_;  ///< указатель на единственный экземпляр класса
    IProject* proj_;        ///< конкретный проект, который использует этот движок
    eState state_;          ///< состояние приложения
    WindowsSpecParams winSpecParams_;/// параметры специфичные для windows-приложения
    HWND hWnd_;             ///< дескриптор окна приложения

    /* Инициализация приложения.
    @return TRUE - успешно, FALSE - ошибка.*/
    BOOL Initialize();
    // Завершить приложение.
    void Terminate();
    // Запустить приложение - войти главный цикл.
    void EnterLoop();
    // Освобождение ресурсов.
    void Clear();
    // Статическая процедура окна.
    static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    // Создание окна.
    BOOL CreateMainWindow();
public:
    /** Кон-р по умолчанию.
    @param params указатель на параметры, специфичные для windows-приложения*/
    App(const WindowsSpecParams* params = 0);
    /** Запуск приложения.
    @param proj указатель на экземпляр проекта
    @return TRUE, если запуск приложения произошел успешно. FALSE - в прот.сл. */
    BOOL Run(IProject* proj);
    /// Получить указатель на приложение.
    static App* GetInstance();
};

} // end of z3D
//-----------------------------------------------------------------------------
/// Прототип функции создания проекта.
z3D::IProject* Z3D_NewProject();
/// Прототип функции удаления проекта.
void Z3D_DeleteProject(z3D::IProject*);
//-----------------------------------------------------------------------------
#endif // WINFRAMEWORK_APP_H


