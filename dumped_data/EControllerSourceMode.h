typedef enum EControllerSourceMode
{
    k_EControllerSourceModeNone = 0,
    k_EControllerSourceModeDpad = 1,
    k_EControllerSourceModeButtons = 2,
    k_EControllerSourceModeFour_buttons = 3,
    k_EControllerSourceModeAbsolute_mouse = 4,
    k_EControllerSourceModeRelative_mouse = 5,
    k_EControllerSourceModeJoystick_move = 6,
    k_EControllerSourceModeJoystick_mouse = 7,
    k_EControllerSourceModeJoystick_camera = 8,
    k_EControllerSourceModeScrollwheel = 9,
    k_EControllerSourceModeTrigger = 10,
    k_EControllerSourceModeTouch_menu = 11,
    k_EControllerSourceModeMouse_joystick = 12,
    k_EControllerSourceModeMouse_region = 13,
    k_EControllerSourceModeRadial_menu = 14,
    k_EControllerSourceModeSingle_button = 15,
    k_EControllerSourceModeSwitches = 16,
    k_EControllerSourceModeFlickstick = 17,
    k_EControllerSourceMode2dscroll = 18,
    k_EControllerSourceModeHotbar = 19,
    k_EControllerSourceModeDisabled = 20,
    k_EControllerSourceModeReference = 21,
} EControllerSourceMode;
