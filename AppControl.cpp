#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>
#include "DrUltraSonic.h"
#include "MdMeasureDistance.h"
#include "MdWBGTMonitor.h"

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;


const char* g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char* g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    setBtnAllFlgFalse();
}
void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{Serial.println("focusChangeImg");
    
     switch(next_state){

        case MENU_WBGT:
            mlcd.clearDisplay();
            mlcd.fillBackgroundWhite();
            mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
            setBtnAllFlgFalse();
        break;

        case MENU_MUSIC:
            mlcd.clearDisplay();
            mlcd.fillBackgroundWhite();
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
            setBtnAllFlgFalse();
        break;

        case MENU_MEASURE:
            mlcd.clearDisplay();
            mlcd.fillBackgroundWhite();
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
            setBtnAllFlgFalse();
        break;

        case MENU_DATE:
            mlcd.clearDisplay();
            mlcd.fillBackgroundWhite();
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
            mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
            setBtnAllFlgFalse();
        break;
        }   
    
}


void AppControl::displayWBGTInit()
{
}

void AppControl::displayTempHumiIndex()
{
}

void AppControl::displayMusicInit()
{
}

void AppControl::displayMusicStop()
{
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
}

void AppControl::displayMeasureInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_MENU_X_CRD, MEASURE_MENU_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_DECIDE_X_CRD, MEASURE_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_UNIT_X_CRD, MEASURE_UNIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DISTANCE_D_X_CRD, MEASURE_DISTANCE_D_Y_CRD);
}

void AppControl::displayMeasureDistance()
{
    double distance = mmdist.getDistance();
    int hundreds = static_cast<int>(distance) / 100;
    int tens = static_cast<int>(distance) / 10 % 10;
    int ones = static_cast<int>(distance) % 10;
    int decimals = static_cast<int>((distance - static_cast<int>(distance)) * 10);

    if (hundreds >= 1 && hundreds <= 9) {
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(g_str_blue[hundreds], MEASURE_DISTANCE_A_X_CRD, MEASURE_DISTANCE_A_Y_CRD);
     };

    if (tens >= 1 && tens <= 9) {
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(g_str_blue[tens], MEASURE_DISTANCE_B_X_CRD, MEASURE_DISTANCE_B_Y_CRD);
    };

    if (tens == 0){
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DISTANCE_B_X_CRD, MEASURE_DISTANCE_B_Y_CRD);
    };

    if (hundreds >= 1 && tens == 0){
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(g_str_blue[hundreds], MEASURE_DISTANCE_A_X_CRD, MEASURE_DISTANCE_A_Y_CRD);
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(g_str_blue[tens], MEASURE_DISTANCE_B_X_CRD, MEASURE_DISTANCE_B_Y_CRD);
    };
            
    if (ones >= 0 && ones <= 9) {
            g_str_blue[ones];
            mlcd.displayJpgImageCoordinate(g_str_blue[ones], MEASURE_DISTANCE_C_X_CRD, MEASURE_DISTANCE_C_Y_CRD);
    };

    if (decimals >= 0 && decimals <= 9) {
            g_str_blue[decimals];
            mlcd.displayJpgImageCoordinate(g_str_blue[decimals], MEASURE_DISTANCE_E_X_CRD, MEASURE_DISTANCE_E_Y_CRD);
    };

    if (hundreds == 0){
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DISTANCE_A_X_CRD, MEASURE_DISTANCE_A_Y_CRD);
    };

    
}    

void AppControl::displayDateInit()
{
}

void AppControl::displayDateUpdate()
{
}

void AppControl::controlApplication()
{
    mmplay.init();

    while (1) {

        switch (getState()) {
        case TITLE:
            switch (getAction()) {
            case ENTRY:
                displayTitleInit();
                setBtnAllFlgFalse();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                setStateMachine(TITLE, EXIT);
                break;

            case EXIT:
                if(m_flag_btnA_is_pressed == true){
                    setStateMachine(MENU, ENTRY);
                }else if(m_flag_btnB_is_pressed == true){
                    setStateMachine(MENU, ENTRY);
                }else if(m_flag_btnC_is_pressed == true){
                    setStateMachine(MENU, ENTRY);
                };
                break;

            default:
                break;
            }

            break;

        case MENU:
            switch (getAction()) {
            case ENTRY:
            Serial.println("menuentry");
                displayMenuInit();
                setStateMachine(MENU, DO);
                setBtnAllFlgFalse();
                setFocusState(MENU_WBGT);
                break;
            case DO:
            Serial.println("menudo");
                
                switch(getFocusState()){
               
                    case MENU_WBGT:
                        if(m_flag_btnA_is_pressed == true){
                            focusChangeImg(MENU_WBGT, MENU_DATE);
                            setFocusState(MENU_DATE);
                        }else if(m_flag_btnC_is_pressed == true){
                            focusChangeImg(MENU_WBGT, MENU_MUSIC);
                            setFocusState(MENU_MUSIC);
                        }else if(m_flag_btnB_is_pressed == true){
                            setStateMachine(MENU, EXIT);
                        }
                        break;
                    
                    case MENU_MUSIC:
                        if(m_flag_btnA_is_pressed == true){
                            focusChangeImg(MENU_MUSIC, MENU_WBGT);
                            setFocusState(MENU_WBGT);
                        }else if(m_flag_btnC_is_pressed == true){
                            focusChangeImg(MENU_MUSIC, MENU_MEASURE);
                            setFocusState(MENU_MEASURE);
                        }else if(m_flag_btnB_is_pressed == true){
                            setStateMachine(MUSIC_STOP, ENTRY);
                        }
                        break;

                    case MENU_MEASURE:
                        if(m_flag_btnA_is_pressed == true){
                            focusChangeImg(MENU_MEASURE, MENU_MUSIC);
                            setFocusState(MENU_MUSIC);
                        }else if(m_flag_btnC_is_pressed == true){
                            focusChangeImg(MENU_MEASURE, MENU_DATE);
                            setFocusState(MENU_DATE);
                        }else if(m_flag_btnB_is_pressed == true){
                            setStateMachine(MEASURE, ENTRY);
                        }
                        break;

                    case MENU_DATE:
                        if(m_flag_btnA_is_pressed == true){
                            focusChangeImg(MENU_DATE, MENU_MEASURE);
                            setFocusState(MENU_MEASURE);
                        }else if(m_flag_btnC_is_pressed == true){
                            focusChangeImg(MENU_DATE, MENU_WBGT);
                            setFocusState(MENU_WBGT);
                        }else if(m_flag_btnB_is_pressed == true){
                            setStateMachine(DATE, ENTRY);
                        }
                        break;
                };
               
                break;
                
            case EXIT:
            Serial.println("menuexit");
                setStateMachine(WBGT, ENTRY);
                break;
            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction()) {
            case ENTRY:

                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
                displayMeasureInit();
                setStateMachine(MEASURE, DO);
                setBtnAllFlgFalse();
                break;

            case DO:
                displayMeasureDistance();
                delay(250);
                if(m_flag_btnB_is_pressed == true){
                    setStateMachine(MEASURE, EXIT);
                };
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
