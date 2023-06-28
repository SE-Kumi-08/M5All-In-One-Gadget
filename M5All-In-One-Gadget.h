/* インクルードガード */
#pragma once

// button gpio number
#define BTN_A_GPIO 39
#define BTN_B_GPIO 38
#define BTN_C_GPIO 37

// UltraSonic pin
#define ECHO_PIN 5
#define TRIG_PIN 2

// HighAndLow Record
#define HAL_ROW 10
#define HAL_COL 2

// trump image path
#define HAL_TITLE_IMG_PATH "/images/trump/title.jpg"
#define HAL_START_IMG_PATH "/images/trump/start.jpg"
#define HAL_RECORD_IMG_PATH "/images/trump/record.jpg"
#define HAL_HIGH_IMG_PATH "/images/trump/high.jpg"
#define HAL_LOW_IMG_PATH "/images/trump/low.jpg"
#define HAL_ONEMORE_IMG_PATH "/images/trump/onemore.jpg"
#define HAL_QUESTION_IMG_PATH "/images/trump/highandlow.jpg"
#define HAL_BACK_IMG_PATH "/images/trump/back.jpg"
#define HAL_WIN_IMG_PATH "/images/trump/win.jpg"
#define HAL_LOSE_IMG_PATH "/images/trump/lose.jpg"

#define HEART_1_IMG_PATH "/images/trump/heart/heart1.jpg"
#define HEART_2_IMG_PATH "/images/trump/heart/heart2.jpg"
#define HEART_3_IMG_PATH "/images/trump/heart/heart3.jpg"
#define HEART_4_IMG_PATH "/images/trump/heart/heart4.jpg"
#define HEART_5_IMG_PATH "/images/trump/heart/heart5.jpg"
#define HEART_6_IMG_PATH "/images/trump/heart/heart6.jpg"
#define HEART_7_IMG_PATH "/images/trump/heart/heart7.jpg"
#define HEART_8_IMG_PATH "/images/trump/heart/heart8.jpg"
#define HEART_9_IMG_PATH "/images/trump/heart/heart9.jpg"

#define SPADE_1_IMG_PATH "/images/trump/spade/spade1.jpg"
#define SPADE_2_IMG_PATH "/images/trump/spade/spade2.jpg"
#define SPADE_3_IMG_PATH "/images/trump/spade/spade3.jpg"
#define SPADE_4_IMG_PATH "/images/trump/spade/spade4.jpg"
#define SPADE_5_IMG_PATH "/images/trump/spade/spade5.jpg"
#define SPADE_6_IMG_PATH "/images/trump/spade/spade6.jpg"
#define SPADE_7_IMG_PATH "/images/trump/spade/spade7.jpg"
#define SPADE_8_IMG_PATH "/images/trump/spade/spade8.jpg"
#define SPADE_9_IMG_PATH "/images/trump/spade/spade9.jpg"

// jpg image path
#define TITLE_IMG_PATH "/images/title/title.jpg"

#define MENU_WBGT_IMG_PATH "/images/menu/monitor.jpg"
#define MENU_WBGT_FOCUS_IMG_PATH "/images/menu/monitor_focus.jpg"
#define MENU_MUSIC_IMG_PATH "/images/menu/music.jpg"
#define MENU_MUSIC_FOCUS_IMG_PATH "/images/menu/music_focus.jpg"
#define MENU_MEASURE_IMG_PATH "/images/menu/measure.jpg"
#define MENU_MEASURE_FOCUS_IMG_PATH "/images/menu/measure_focus.jpg"
#define MENU_DATE_IMG_PATH "/images/menu/date.jpg"
#define MENU_DATE_FOCUS_IMG_PATH "/images/menu/date_focus.jpg"

#define WBGT_SAFE_IMG_PATH "/images/wbgt/safe.jpg"
#define WBGT_ATTENTION_IMG_PATH "/images/wbgt/attention.jpg"
#define WBGT_ALERT_IMG_PATH "/images/wbgt/alert.jpg"
#define WBGT_HIGH_ALERT_IMG_PATH "/images/wbgt/high_alert.jpg"
#define WBGT_DANGER_IMG_PATH "/images/wbgt/danger.jpg"
#define WBGT_TEMPERATURE_IMG_PATH "/images/wbgt/temperature.jpg"
#define WBGT_HUMIDITY_IMG_PATH "/images/wbgt/humidity.jpg"
#define WBGT_DEGREE_IMG_PATH "/images/wbgt/degree.jpg"
#define WBGT_PERCENT_IMG_PATH "/images/wbgt/percent.jpg"

#define MUSIC_NOWPLAYING_IMG_PATH "/images/music/nowplaying.jpg"
#define MUSIC_NOWSTOPPING_IMG_PATH "/images/music/nowstopping.jpg"

#define MEASURE_NOTICE_IMG_PATH "/images/measure/measure.jpg"
#define MEASURE_CM_IMG_PATH "/images/measure/cm.jpg"

#define DATE_NOTICE_IMG_PATH "/images/date/notice.jpg"
#define DATE_SLASH_IMG_PATH "/images/date/slash.jpg"
#define DATE_COLON_IMG_PATH "/images/date/colon.jpg"

#define COMMON_BUTTON_BACK_IMG_PATH "/images/common/button/back.jpg"
#define COMMON_BUTTON_DECIDE_IMG_PATH "/images/common/button/decide.jpg"
#define COMMON_BUTTON_DOWN_IMG_PATH "/images/common/button/down.jpg"
#define COMMON_BUTTON_NEXT_IMG_PATH "/images/common/button/next.jpg"
#define COMMON_BUTTON_PLAY_IMG_PATH "/images/common/button/play.jpg"
#define COMMON_BUTTON_STOP_IMG_PATH "/images/common/button/stop.jpg"
#define COMMON_BUTTON_UP_IMG_PATH "/images/common/button/up.jpg"
#define COMMON_BUTTON_FILLWHITE_IMG_PATH "/images/common/button/fillwhite.jpg"

#define COMMON_ORANGE1_IMG_PATH "/images/common/orange_number/1.jpg"
#define COMMON_ORANGE2_IMG_PATH "/images/common/orange_number/2.jpg"
#define COMMON_ORANGE3_IMG_PATH "/images/common/orange_number/3.jpg"
#define COMMON_ORANGE4_IMG_PATH "/images/common/orange_number/4.jpg"
#define COMMON_ORANGE5_IMG_PATH "/images/common/orange_number/5.jpg"
#define COMMON_ORANGE6_IMG_PATH "/images/common/orange_number/6.jpg"
#define COMMON_ORANGE7_IMG_PATH "/images/common/orange_number/7.jpg"
#define COMMON_ORANGE8_IMG_PATH "/images/common/orange_number/8.jpg"
#define COMMON_ORANGE9_IMG_PATH "/images/common/orange_number/9.jpg"
#define COMMON_ORANGE0_IMG_PATH "/images/common/orange_number/0.jpg"
#define COMMON_ORANGEDOT_IMG_PATH "/images/common/orange_number/dot.jpg"
#define COMMON_ORANGEFILLWHITE_IMG_PATH "/images/common/orange_number/fillwhite.jpg"

#define COMMON_BLUE1_IMG_PATH "/images/common/blue_number/1.jpg"
#define COMMON_BLUE2_IMG_PATH "/images/common/blue_number/2.jpg"
#define COMMON_BLUE3_IMG_PATH "/images/common/blue_number/3.jpg"
#define COMMON_BLUE4_IMG_PATH "/images/common/blue_number/4.jpg"
#define COMMON_BLUE5_IMG_PATH "/images/common/blue_number/5.jpg"
#define COMMON_BLUE6_IMG_PATH "/images/common/blue_number/6.jpg"
#define COMMON_BLUE7_IMG_PATH "/images/common/blue_number/7.jpg"
#define COMMON_BLUE8_IMG_PATH "/images/common/blue_number/8.jpg"
#define COMMON_BLUE9_IMG_PATH "/images/common/blue_number/9.jpg"
#define COMMON_BLUE0_IMG_PATH "/images/common/blue_number/0.jpg"
#define COMMON_BLUEDOT_IMG_PATH "/images/common/blue_number/dot.jpg"
#define COMMON_BLUEFILLWHITE_IMG_PATH "/images/common/blue_number/fillwhite.jpg"

//TRUMP image coordinate
#define HAL_TITLE_X_CRD 0
#define HAL_TITLE_Y_CRD 0
#define HAL_START_X_CRD 0
#define HAL_START_Y_CRD 200
#define HAL_RECORD_X_CRD 240
#define HAL_RECORD_Y_CRD 200
#define HAL_BACKBTN_X_CRD 120
#define HAL_BACKBTN_Y_CRD 200

#define HAL_LEFTTRUMP_X_CRD 45
#define HAL_LEFTTRUMP_Y_CRD 10
#define HAL_RIGHTTRUMP_X_CRD 195
#define HAL_RIGHTTRUMP_Y_CRD 10
#define HAL_QUESTION_X_CRD 20
#define HAL_QUESTION_Y_CRD 140
#define HAL_HIGH_X_CRD 0
#define HAL_HIGH_Y_CRD 200
#define HAL_LOW_X_CRD 240
#define HAL_LOW_Y_CRD 200

#define HAL_WIN_X_CRD 80
#define HAL_WIN_Y_CRD 140
#define HAL_LOSE_X_CRD 110
#define HAL_LOSE_Y_CRD 140
#define HAL_ONEMORE_X_CRD 0
#define HAL_ONEMORE_Y_CRD 200

// TITLE jpg image coordinate
#define TITLE_X_CRD 0
#define TITLE_Y_CRD 0

// MENU jpg image coordinate
#define MENU_WBGT_X_CRD 0
#define MENU_WBGT_Y_CRD 0
#define MENU_MUSIC_X_CRD 0
#define MENU_MUSIC_Y_CRD 50
#define MENU_MEASURE_X_CRD 0
#define MENU_MEASURE_Y_CRD 100
#define MENU_DATE_X_CRD 0
#define MENU_DATE_Y_CRD 150
#define MENU_UP_X_CRD 0
#define MENU_UP_Y_CRD 200
#define MENU_DOWN_X_CRD 240
#define MENU_DOWN_Y_CRD 200
#define MENU_DECIDE_X_CRD 120
#define MENU_DECIDE_Y_CRD 200
 
// WBGT jpg image coordinate
#define WBGT_TEMPERATURE_X_CRD 0
#define WBGT_TEMPERATURE_Y_CRD 0
#define WBGT_T2DIGIT_X_CRD 120
#define WBGT_T2DIGIT_Y_CRD 0
#define WBGT_T1DIGIT_X_CRD 153
#define WBGT_T1DIGIT_Y_CRD 0
#define WBGT_TDOT_X_CRD 186
#define WBGT_TDOT_Y_CRD 0
#define WBGT_T1DECIMAL_X_CRD 220
#define WBGT_T1DECIMAL_Y_CRD 0
#define WBGT_DEGREE_X_CRD 253
#define WBGT_DEGREE_Y_CRD 0

#define WBGT_HUMIDITY_X_CRD 0
#define WBGT_HUMIDITY_Y_CRD 50
#define WBGT_H2DIGIT_X_CRD 120
#define WBGT_H2DIGIT_Y_CRD 50
#define WBGT_H1DIGIT_X_CRD 153
#define WBGT_H1DIGIT_Y_CRD 50
#define WBGT_HDOT_X_CRD 186
#define WBGT_HDOT_Y_CRD 50
#define WBGT_H1DECIMAL_X_CRD 220
#define WBGT_H1DECIMAL_Y_CRD 50
#define WBGT_PERCENT_X_CRD 253
#define WBGT_PERCENT_Y_CRD 50

#define WBGT_NOTICE_X_CRD 0
#define WBGT_NOTICE_Y_CRD 100
#define WBGT_BACK_X_CRD 120
#define WBGT_BACK_Y_CRD 200

// Music jpg image coordinate
#define MUSIC_NOTICE_X_CRD 0
#define MUSIC_NOTICE_Y_CRD 0
#define MUSIC_TITLE_X_CRD 10
#define MUSIC_TITLE_Y_CRD 120
#define MUSIC_PLAY_X_CRD 0	
#define MUSIC_PLAY_Y_CRD 200	
#define MUSIC_BACK_X_CRD 120
#define MUSIC_BACK_Y_CRD 200	
#define MUSIC_NEXT_X_CRD 240	
#define MUSIC_NEXT_Y_CRD 200	
#define MUSIC_STOP_X_CRD 0	
#define MUSIC_STOP_Y_CRD 200	

// Measure jpg image coordinate
#define MEASURE_NOTICE_X_CRD 0
#define MEASURE_NOTICE_Y_CRD 0
#define MEASURE_BACK_X_CRD 120
#define MEASURE_BACK_Y_CRD 200
#define MEASURE_CM_X_CRD 240
#define MEASURE_CM_Y_CRD 100

#define MEASURE_DIGIT3_X_CRD 10
#define MEASURE_DIGIT3_Y_CRD 100
#define MEASURE_DIGIT2_X_CRD 53
#define MEASURE_DIGIT2_Y_CRD 100
#define MEASURE_DIGIT1_X_CRD 96
#define MEASURE_DIGIT1_Y_CRD 100
#define MEASURE_DOT_X_CRD 139
#define MEASURE_DOT_Y_CRD 100
#define MEASURE_DECIMAL_X_CRD 182
#define MEASURE_DECIMAL_Y_CRD 100

// Date jpg image coordinate
#define DATE_NOTICE_X_CRD 0
#define DATE_NOTICE_Y_CRD 0
#define DATE_YYYYMMDD_X_CRD 10	
#define DATE_YYYYMMDD_Y_CRD 100	
#define DATE_HHmmSS_X_CRD 40	
#define DATE_HHmmSS_Y_CRD 150	
#define DATE_BACK_X_CRD 120	
#define DATE_BACK_Y_CRD 200	

typedef enum {
    TITLE,
    MENU,
    WBGT,
    MUSIC_STOP,
    MUSIC_PLAY,
    MEASURE,
    DATE,
    HAL_TITLE,
    HAL_BATTLE,
    HAL_RESULT,
    HAL_RECORD
} State;

typedef enum {
    ENTRY,
    DO,
    EXIT
} Action;

typedef enum {
    MENU_WBGT,
    MENU_MUSIC,
    MENU_MEASURE,
    MENU_DATE
} FocusState;

typedef enum {
    SAFE,
    ATTENTION,
    ALERT,
    HIGH_ALERT,
    DANGER
} WbgtIndex;

typedef enum{
    UP,
    DOWN,
    DECIDE
}HALCommand;

typedef enum{
    HAL_HIGH,
    HAL_LOW
}HALAnswer;