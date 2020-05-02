package com.example.android_demo.k.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

import java.io.InputStream;

public class MyView extends View {
	
	private String mtext;
	private int msrc;

	public MyView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
	}

	public MyView(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
		
		int resourceId = 0;
		
		int textId = attrs.getAttributeResourceValue(null, "Text",0);
		int srcId = attrs.getAttributeResourceValue(null, "Src", 0);
		
		mtext = context.getResources().getText(textId).toString();
		msrc = srcId;
	
	}

	
	@Override
	protected void onDraw(Canvas canvas) {
		// TODO Auto-generated method stub
		
		Paint paint = new Paint();
		paint.setColor(Color.RED);
		InputStream is = getResources().openRawResource(msrc);
		
        Bitmap mBitmap = BitmapFactory.decodeStream(is);
		
        //图片和文字的位置需要再定？还有问题
        
		canvas.drawBitmap(mBitmap, 0,0, paint);
		int w = mBitmap.getWidth();
		int h = mBitmap.getHeight();
		
		//canvas.drawCircle(40, 90, 15, paint);
		
		canvas.drawText(mtext, w/2, 20, paint);
	}
	
	

}