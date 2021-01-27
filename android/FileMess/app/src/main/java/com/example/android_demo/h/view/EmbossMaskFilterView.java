package com.example.android_demo.h.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.EmbossMaskFilter;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

import com.example.android_demo.R;

public class EmbossMaskFilterView extends View {

    public EmbossMaskFilterView(Context context) {
        super(context);
    }

    public EmbossMaskFilterView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public EmbossMaskFilterView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        float[] direction = new float[]{ 1, 1, 3 };   // 设置光源的方向
        float light = 0.4f;     //设置环境光亮度
        float specular = 8;     // 定义镜面反射系数
        float blur = 3.0f;      //模糊半径
        EmbossMaskFilter emboss = new EmbossMaskFilter(direction,light,specular,blur);

        Paint paint = new Paint();
        paint.setAntiAlias(true);          //抗锯齿
        paint.setColor(Color.BLUE);//画笔颜色
        paint.setStyle(Paint.Style.FILL);  //画笔风格
        paint.setTextSize(70);             //绘制文字大小，单位px
        paint.setStrokeWidth(8);           //画笔粗细
        paint.setMaskFilter(emboss);
        canvas.drawText("最喜欢看曹神日狗了~", 50, 100, paint);

        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.pre1);
        canvas.drawBitmap(bitmap, 10, 100, paint);

        setLayerType(View.LAYER_TYPE_SOFTWARE, null);     //关闭硬件加速
    }
}