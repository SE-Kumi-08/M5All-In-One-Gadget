/* インクルードガード */
#pragma once

#include "M5All-In-One-Gadget.h"
#include <Arduino.h>

class MdHighAndLow // classの定義
{
private: // privateはクラス内からしかアクセスできない
    int m_leftnum;
    int m_rightnum;
    int m_straight_wins;
    HALAnswer m_ans;
    String m_tmp_record[HAL_ROW][HAL_COL];

public: // publicはどこからでもアクセス可能
    void setCardNumber();
    int getLeftNumber();
    int getRightNumber();
    void setResult(HALAnswer ans);
    bool getResult();
    void readRecord(String rcd[HAL_ROW][HAL_COL]);
    void setRecord();
    void getRecord(String rcd[HAL_ROW][HAL_COL]);
    void saveRecord(String btl_time);
    void incrementWins();
    void resetWins();
};