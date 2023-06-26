#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>
#include "DrUltraSonic.h"
#include "MdMeasureDistance.h"
#include "MdWBGTMonitor.h"
#include "MdMusicPlayer.h"
#include "MdDateTime.h"

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
{
     switch(current_state){

        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;

        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
        break;

        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;

        case MENU_DATE:
            mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
        }   


     switch(next_state){

        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;

        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_MUSIC_Y_CRD);
        break;

        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;

        case MENU_DATE:
            mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
        }   
    
}


void AppControl::displayWBGTInit()
{   
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
}

void AppControl::displayTempHumiIndex()
{   
    mwbgt.init();
    double temp, humi; 
    WbgtIndex index; 
    mwbgt.getWBGT(&temp, &humi, &index);

    int tp = temp * 10;
    int hm = humi * 10;
    int temp_disit = 1;
    int humi_disit = 1;

    for(temp_disit = 1; temp_disit <= 3; temp_disit++){
    
            switch(temp_disit){
                case 1:
                    mlcd.displayJpgImageCoordinate(g_str_orange[tp % 10], WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
                break;
                case 2:
                    mlcd.displayJpgImageCoordinate(g_str_orange[tp % 10], WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
                break;
                case 3:
                if(tp % 10 == 0){
                    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
                }else{
                    mlcd.displayJpgImageCoordinate(g_str_orange[tp % 10], WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
                }
                break;
            }
            tp = tp / 10;
    }
    

    for(humi_disit = 1; humi_disit <= 3; humi_disit++){
    
            switch(humi_disit){
                case 1:
                    mlcd.displayJpgImageCoordinate(g_str_blue[hm % 10], WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
                break;
                case 2:
                    mlcd.displayJpgImageCoordinate(g_str_blue[hm % 10], WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
                break;
                case 3:
                if(hm % 10 == 0){
                    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
                }else{
                    mlcd.displayJpgImageCoordinate(g_str_blue[hm % 10], WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
                }
                break;
            }
            hm = hm / 10;
    }

    switch(index){
        case SAFE:
            mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
        case ATTENTION:
            mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
        case ALERT:
            mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
        case HIGH_ALERT:
            mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
        case DANGER:
            mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);

    }
}

void AppControl::displayMusicInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_STOP_X_CRD, MUSIC_STOP_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayMusicStop()
{
    mmplay.stopMP3();
}

void AppControl::displayMusicTitle()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}


void AppControl::displayNextMusic()
{   
    mlcd.displayText("                     ", MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
    mmplay.selectNextMusic();
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayMusicPlay()
{
    mmplay.prepareMP3();
    mmplay.isRunningMP3();
}

void AppControl::displayMeasureInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
}

void AppControl::displayMeasureDistance()
{
    double distance = mmdist.getDistance();
    int dt_disit;
    int dt = distance * 10;
    delay(250);

    for(dt_disit = 1; dt_disit <= 4; dt_disit++){
    
            switch(dt_disit){
                case 1:
                mlcd.displayJpgImageCoordinate(g_str_blue[dt % 10], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
                break;
                case 2:
                mlcd.displayJpgImageCoordinate(g_str_blue[dt % 10], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
                break;
                case 3:
                if(dt % 10 == 0 && dt % 100 == 0){
                    mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
                }else{
                    mlcd.displayJpgImageCoordinate(g_str_blue[dt % 10], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
                }
                break;
                case 4:
                if(dt % 10 == 0){
                    mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
                }else{
                    mlcd.displayJpgImageCoordinate(g_str_blue[dt % 10], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
                }
                break;
            }
            dt = dt / 10;
    }

    /*if (hundreds >= 1 && hundreds <= 9) {
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(g_str_blue[hundreds], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
     };

    if (tens >= 1 && tens <= 9) {
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(g_str_blue[tens], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    };

    if (tens == 0){
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    };

    if (hundreds >= 1 && tens == 0){
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(g_str_blue[hundreds], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
            g_str_blue[tens];
            mlcd.displayJpgImageCoordinate(g_str_blue[tens], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
    };
            
    if (ones >= 0 && ones <= 9) {
            g_str_blue[ones];
            mlcd.displayJpgImageCoordinate(g_str_blue[ones], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
    };

    if (decimals >= 0 && decimals <= 9) {
            g_str_blue[decimals];
            mlcd.displayJpgImageCoordinate(g_str_blue[decimals], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
    };

    if (hundreds == 0){
            g_str_blue[hundreds];
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
    };*/

    
}    

void AppControl::displayDateInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
}

void AppControl::controlApplication()
{
    mmplay.init();
    int flag_btnC = 0;
    int flag_btnA = 0;

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
                displayMenuInit();
                setStateMachine(MENU, DO);
                setBtnAllFlgFalse();
                setFocusState(MENU_WBGT);
                break;
            case DO:              
                if(m_flag_btnA_is_pressed == true){
                        flag_btnA++;
                        Serial.println("flag_btnA");
                    };
                    if(m_flag_btnC_is_pressed == true && flag_btnA >= flag_btnC){
                        flag_btnC++;
                        Serial.println("flag_btnC");
                        if(flag_btnC == 2 && flag_btnA == 2){
                            Serial.println("setStateMachine");
                            setStateMachine(HIGH_AND_LOW, ENTRY);
                        };
                    };
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
                        setBtnAllFlgFalse();
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
                        setBtnAllFlgFalse();
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
                        setBtnAllFlgFalse();
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
                        setBtnAllFlgFalse();
                        break;
                    
                    };
               
                break;
                
            case EXIT:
            
                setStateMachine(WBGT, ENTRY);
                break;
            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction()) {
            case ENTRY:
                displayWBGTInit();
                setStateMachine(WBGT, DO);
                setBtnAllFlgFalse();
                break;

            case DO:
                while(m_flag_btnB_is_pressed == false){
                    displayTempHumiIndex();
                    delay(100);
                };
                setStateMachine(WBGT, EXIT);
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                displayMusicTitle();
                setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
                if(m_flag_btnB_is_pressed == true){
                    setStateMachine(MENU, ENTRY);
                }else if(m_flag_btnC_is_pressed == true){
                    displayNextMusic();
                    setBtnAllFlgFalse();
                }else if(m_flag_btnA_is_pressed == true){
                    setStateMachine(MUSIC_STOP, EXIT);
                };
                break;
                
            case EXIT:
                setStateMachine(MUSIC_PLAY, ENTRY);
                break;
            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                setStateMachine(MUSIC_PLAY, DO);
                displayMusicPlay();
                displayMusicInit();
                setBtnAllFlgFalse();
                break;

            case DO:   
                do{
                    if(m_flag_btnA_is_pressed == true || mmplay.playMP3() == false){
                        displayMusicStop();
                        setStateMachine(MUSIC_PLAY, EXIT);
                        setBtnAllFlgFalse();
                    };
                }while(mmplay.playMP3());
                    
                break;

            case EXIT:
                setStateMachine(MUSIC_STOP, ENTRY);
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
               while(m_flag_btnB_is_pressed == false){
                    displayMeasureDistance();
               };
                setStateMachine(MEASURE, EXIT);
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
                setStateMachine(DATE, DO);
                displayDateInit();
                setBtnAllFlgFalse();
                break;

            case DO:
                while(m_flag_btnB_is_pressed == false){
                    displayDateUpdate();
                    delay(100);
                };
                setStateMachine(DATE, EXIT);
                break;
            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;
            default:
                break;
            }

        case HIGH_AND_LOW:

            switch (getAction()) {
            case ENTRY:
                setStateMachine(HIGH_AND_LOW, DO);
                mlcd.clearDisplay();
                mlcd.fillBackgroundWhite();
                mlcd.displayJpgImageCoordinate(TRUMP_TITLE_IMG_PATH, TRUMP_TITLE_X_CRD, TRUMP_TITLE_Y_CRD);
                mlcd.displayJpgImageCoordinate(TRUMP_TITLE_START_IMG_PATH, TRUMP_TITLE_START_X_CRD, TRUMP_TITLE_START_Y_CRD);
                mlcd.displayJpgImageCoordinate(TRUMP_TITLE_BACK_IMG_PATH, TRUMP_TITLE_BACK_X_CRD, TRUMP_TITLE_BACK_Y_CRD);
                mlcd.displayJpgImageCoordinate(TRUMP_TITLE_RECORD_IMG_PATH, TRUMP_TITLE_RECORD_X_CRD, TRUMP_TITLE_RECORD_Y_CRD);
                setBtnAllFlgFalse();
                break;

            case DO:
                if(m_flag_btnB_is_pressed == true){
                    setStateMachine(HIGH_AND_LOW, EXIT);
                }else if(m_flag_btnA_is_pressed == true){
                    
                }else if(m_flag_btnC_is_pressed == true){

                }
                
                break;
            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;
            default:
                break;
            }

        default:
            break;
        }
    }
}
