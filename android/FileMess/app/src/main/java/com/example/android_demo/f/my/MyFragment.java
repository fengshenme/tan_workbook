package com.example.android_demo.f.my;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import com.example.android_demo.R;


/**
 * Created by Jay on 2015/8/28 0028.
 */
public class MyFragment extends Fragment {


    public MyFragment(){}

    public static MyFragment newInstance( String content) {

        MyFragment fragment = new MyFragment();
        if(content != null&& !"".equals(content)){
            Bundle bundle = new Bundle();
            bundle.putString("strContent", content);
            fragment.setArguments(bundle);
        }

        return fragment ;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_content_a,container,false);
        TextView txt_content = view.findViewById(R.id.txt_content_a);
        String content = "a-----";
        if (getArguments() != null) {
            content = getArguments().getString("strContent");
        }
        System.out.println("37----"+getArguments().getString("strContent"));

        txt_content.setText(content);

        return view;
    }
}
