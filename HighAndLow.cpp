#include <CSV_Parser.h>
#include "HighAndLow.h"
#include <stdlib.h>
#include <time.h>
#include <SD.h>

void MdHighAndLow::setCardNumber(){
    srand((unsigned int)time(NULL));
    //左用ランダム数値の取得
    m_leftnum = rand() % 9 + 1;

	do {
		//右用ランダム数値の取得
		m_rightnum = rand() % 9 + 1;
	} while (m_leftnum == m_rightnum);
}

int MdHighAndLow::getLeftNumber(){
    return m_leftnum;
}

int MdHighAndLow::getRightNumber(){
    return m_rightnum;
}

void MdHighAndLow::setResult(HALAnswer ans){
    m_ans = ans;
}

bool MdHighAndLow::getResult(){

    // 正解だった場合trueを返す
    bool result = true;

    if(m_ans == HAL_HIGH){
        if(m_leftnum > m_rightnum){
            result = false;
        }
        else{
            result = true;
        }
    }else if(m_ans == HAL_LOW){
        if(m_leftnum > m_rightnum){
            result = true;
        }
        else{
            result = false;
        }
    }
    return result;
}

void MdHighAndLow::readRecord(String rcd[HAL_ROW][HAL_COL]){

    if(!SD.begin()) {        
        for(int row = 0; row < 10; row++){
            for(int col = 0; col < 10; col++){
                rcd[row][col] = "";
            }
        }
        rcd[0][0] =  "Card Error!";
    }else{

        CSV_Parser cp(/*format*/ "ss",  /*delimiter*/ ',');

        if(cp.readSDfile("/record.csv")) {

            char **btl_date = (char**)cp["date"];
            char **btl_wins = (char**)cp["wins"];

            for(int row=0; row<cp.getRowsCount(); row++) {
                Serial.print(btl_date[row]);
                Serial.print(" , ");
                Serial.println(btl_wins[row]);
                rcd[row][0] = btl_date[row];
                rcd[row][1] = btl_wins[row];
            }

        } else {                       
            for(int row = 0; row < 10; row++){
                for(int col = 0; col < 10; col++){
                    rcd[row][col] = "";
                }
            }
            rcd[0][0] = "File open error.";
        }
    }
}

void MdHighAndLow::setRecord(){
    readRecord(m_tmp_record);
}

void MdHighAndLow::getRecord(String rcd[HAL_ROW][HAL_COL]){
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 2; col++){
            rcd[row][col] = m_tmp_record[row][col];
        }
    }
}

void MdHighAndLow::saveRecord(String btl_time){
    for(int row = 0; row < HAL_ROW -1; row++){
        m_tmp_record[HAL_ROW - 1 - row][0] = m_tmp_record[HAL_ROW - 2 - row][0];
        m_tmp_record[HAL_ROW - 1 - row][1] = m_tmp_record[HAL_ROW - 2 - row][1];
    }
    m_tmp_record[0][0] = btl_time;
    m_tmp_record[0][1] = String(m_straight_wins) + " straight wins";
    resetWins();

    File file;
    file = SD.open("/record.csv", FILE_WRITE);
    file.println("date,wins");
    for(int row = 0; row < HAL_ROW; row++){
        file.println(m_tmp_record[row][0] + "," + m_tmp_record[row][1]);
        Serial.println(m_tmp_record[row][0] + "," + m_tmp_record[row][1]);
    }
    file.close();
}

void MdHighAndLow::incrementWins(){
    m_straight_wins++;
}

void MdHighAndLow::resetWins(){
    m_straight_wins = 0;
}