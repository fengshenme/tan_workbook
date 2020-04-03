package com.example.demoone.h.view;

import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

import com.example.demoone.h.entity.ColorEvaluator;
import com.example.demoone.h.entity.Point;
import com.example.demoone.h.entity.PointEvaluator;

public class AnimView2 extends View {

    public static final float RADIUS = 80.0f;
    private Point currentPoint;
    private Paint mPaint;
    private int mColor;

    public AnimView2(Context context) {
        this(context, null);
    }

    public AnimView2(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public AnimView2(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    private void init() {
        mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        mPaint.setColor(Color.BLUE);
    }



    private void drawCircle(Canvas canvas){
        float x = currentPoint.getX();
        float y = currentPoint.getY();
        canvas.drawCircle(x, y, RADIUS, mPaint);
    }

    private void startAnimation() {
        Point startPoint = new Point(RADIUS, RADIUS);
        Point endPoint = new Point(getWidth() - RADIUS, getHeight() - RADIUS);
        ValueAnimator anim = ValueAnimator.ofObject(new PointEvaluator(), startPoint, endPoint);
        anim.addUpdateListener(new ValueAnimator.AnimatorUpdateListener() {
            @Override
            public void onAnimationUpdate(ValueAnimator animation) {
                currentPoint = (Point) animation.getAnimatedValue();
                invalidate();
            }
        });

        ObjectAnimator objectAnimator = ObjectAnimator.ofObject(this, "color", new ColorEvaluator(),
                Color.BLUE, Color.RED);
        //动画集合将前面两个动画加到一起，with同时播放
        AnimatorSet animatorSet = new AnimatorSet();
        animatorSet.play(anim).with(objectAnimator);
        animatorSet.setStartDelay(1000l);
        animatorSet.setDuration(3000l);
        animatorSet.start();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        if (currentPoint == null) {
            currentPoint = new Point(RADIUS, RADIUS);
            drawCircle(canvas);
            startAnimation();
        } else {
            drawCircle(canvas);
        }
    }

    //color的get和set方法~
    public int getColor() {
        return mColor;
    }

    public void setColor(int color) {
        mColor = color;
        mPaint.setColor(color);
        invalidate();
    }
}