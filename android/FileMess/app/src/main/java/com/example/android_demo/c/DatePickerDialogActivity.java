package com.example.android_demo.c;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TimePicker;
import android.widget.Toast;


import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

import java.util.Calendar;

public class DatePickerDialogActivity extends AppCompatActivity implements View.OnClickListener{

    private Button btn_date, btn_time;
    private String result = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_date_picker_dialog);
        bindViews();
    }

    private void bindViews() {
        btn_date = findViewById(R.id.btn_date);
        btn_time = findViewById(R.id.btn_time);

        btn_date.setOnClickListener(this);
        btn_time.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        result = "";
        switch (v.getId()){
            case R.id.btn_date:
                Calendar cale1 = Calendar.getInstance();
                new DatePickerDialog(DatePickerDialogActivity.this,new DatePickerDialog.OnDateSetListener() {
                    @Override
                    public void onDateSet(DatePicker view, int year, int monthOfYear,
                                          int dayOfMonth) {
                        //这里获取到的月份需要加上1哦~
                        result += "你选择的是"+year+"年"+(monthOfYear+1)+"月"+dayOfMonth+"日";
                        Toast.makeText(getApplicationContext(), result, Toast.LENGTH_SHORT).show();
                    }
                }
                        ,cale1.get(Calendar.YEAR)
                        ,cale1.get(Calendar.MONTH)
                        ,cale1.get(Calendar.DAY_OF_MONTH)).show();
                break;
            case R.id.btn_time:
                Calendar cale2 = Calendar.getInstance();
                new TimePickerDialog(DatePickerDialogActivity.this, new TimePickerDialog.OnTimeSetListener() {
                    @Override
                    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                        result = "";
                        result += "您选择的时间是:"+hourOfDay+"时"+minute+"分";
                        Toast.makeText(getApplicationContext(), result, Toast.LENGTH_SHORT).show();
                    }
                }, cale2.get(Calendar.HOUR_OF_DAY), cale2.get(Calendar.MINUTE), true).show();
                break;
        }
    }

}
