package com.example.demoone.component;

import android.database.Cursor;
import android.provider.ContactsContract;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.SimpleCursorAdapter;

import com.example.demoone.R;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ArrayAdapterActivity extends AppCompatActivity {

    private String[] names = new String[]{"B神", "基神", "曹神"};
    private String[] says = new String[]{"无形被黑，最为致命", "大神好厉害~", "我将带头日狗~"};
    private int[] imgIds = new int[]{R.mipmap.s_1, R.mipmap.s_2, R.mipmap.s_3};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_array_adapter);
        //要显示的数据
//        String[] strs = {"基神","B神","翔神","曹神","J神"};
//        //创建ArrayAdapter
//        ArrayAdapter<String> adapter = new ArrayAdapter<String>
//                (this,android.R.layout.simple_expandable_list_item_1,strs);
//        //获取ListView对象，通过调用setAdapter方法为ListView设置Adapter设置适配器
//        ListView list_test =  findViewById(R.id.list_test);
//        list_test.setAdapter(adapter);

        List<Map<String, Object>> listitem = new ArrayList<Map<String, Object>>();
        for (int i = 0; i < names.length; i++) {
            Map<String, Object> showitem = new HashMap<String, Object>();
            showitem.put("touxiang", imgIds[i]);
            showitem.put("name", names[i]);
            showitem.put("says", says[i]);
            listitem.add(showitem);
        }

        //创建一个simpleAdapter
        SimpleAdapter myAdapter = new SimpleAdapter(getApplicationContext(), listitem, R.layout.list_item,
                new String[]{"touxiang", "name", "says"},
                new int[]{R.id.imgtou, R.id.name, R.id.says});
        ListView listView = findViewById(R.id.list_test);
        listView.setAdapter(myAdapter);

        

    }
}
