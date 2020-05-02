package com.example.android_demo.e.common;

/**
 * 定义一个延时操作，用于模拟下载：
 *
 */
public class DelayOperator {
    //延时操作,用来模拟下载  
    public void delay()  
    {  
        try {  
            Thread.sleep(1000);  
        }catch (InterruptedException e){  
            e.printStackTrace();;  
        }  
    }  
}