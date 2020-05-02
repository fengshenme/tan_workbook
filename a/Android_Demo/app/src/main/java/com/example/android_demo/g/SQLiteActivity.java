package com.example.android_demo.g;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;
import com.example.android_demo.g.entity.Person;
import com.example.android_demo.g.utils.MyDBOpenHelper;

public class SQLiteActivity extends AppCompatActivity implements View.OnClickListener {


    private Context mContext;
    private Button btn_insert;
    private Button btn_query;
    private Button btn_update;
    private Button btn_delete;
    private SQLiteDatabase db;
    private MyDBOpenHelper myDBHelper;
    private StringBuilder sb;
    private int i = 1;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_s_q_lite);

        mContext = SQLiteActivity.this;
        myDBHelper = new MyDBOpenHelper(mContext, "my.db", null, 1);
        bindViews();
    }

    private void bindViews() {
        btn_insert = (Button) findViewById(R.id.btn_insert);
        btn_query = (Button) findViewById(R.id.btn_query);
        btn_update = (Button) findViewById(R.id.btn_update);
        btn_delete = (Button) findViewById(R.id.btn_delete);

        btn_query.setOnClickListener(this);
        btn_insert.setOnClickListener(this);
        btn_update.setOnClickListener(this);
        btn_delete.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        db = myDBHelper.getWritableDatabase();
        switch (v.getId()) {
            case R.id.btn_insert:
                Person p = new Person();
                p.setName("呵呵~"+ i);
                p.setPhone("aa"+ i);
                db.execSQL("INSERT INTO person(name,phone) values(?,?)",
                        new String[]{p.getName(),p.getPhone()});
                ContentValues values1 = new ContentValues();
                i++;
                //参数依次是：表名，强行插入null值得数据列的列名，一行记录的数据
//                db.insert("person", null, values1);
                Toast.makeText(mContext, "插入完毕~", Toast.LENGTH_SHORT).show();
                break;
            case R.id.btn_query:
                sb = new StringBuilder();
//                Integer id = 9;
//                Cursor cursor =  db.rawQuery("SELECT * FROM person WHERE personid = ?", new String[]{id.toString()});
                Cursor cursor =  db.rawQuery("SELECT * FROM person ", null);
                //参数依次是:表名，列名，where约束条件，where中占位符提供具体的值，指定group by的列，进一步约束
                //指定查询结果的排序方式
                if (cursor.moveToFirst()) {
                    do {
                        int personid = cursor.getInt(cursor.getColumnIndex("personid"));
                        String name = cursor.getString(cursor.getColumnIndex("name"));
                        String phone = cursor.getString(cursor.getColumnIndex("phone"));
                        sb.append("id：" + personid + "：" + name + ","+phone+"\n");
                    } while (cursor.moveToNext());
                }
                cursor.close();
                Toast.makeText(mContext, sb.toString(), Toast.LENGTH_SHORT).show();
                break;
            case R.id.btn_update:
                ContentValues values2 = new ContentValues();
                values2.put("name", "嘻嘻~");
                //参数依次是表名，修改后的值，where条件，以及约束，如果不指定三四两个参数，会更改所有行
                db.update("person", values2, "name = ?", new String[]{"呵呵~2"});
                break;
            case R.id.btn_delete:
                //参数依次是表名，以及where条件与约束
                db.delete("person", "personid = ?", new String[]{"1"});
                break;
        }
    }

}
/**
 * 1.插入数据
 * public void save(Person p)
 * {
 *     SQLiteDatabase db = dbOpenHelper.getWritableDatabase();
 *     db.execSQL("INSERT INTO person(name,phone) values(?,?)",
 *                 new String[]{p.getName(),p.getPhone()});
 * }
 * 2.删除数据：
 * public void delete(Integer id)
 * {
 *     SQLiteDatabase db = dbOpenHelper.getWritableDatabase();
 *     db.execSQL("DELETE FROM person WHERE personid = ?",
 *                 new String[]{id});
 * }
 * 3.修改数据：
 * public void update(Person p)
 * {
 *     SQLiteDatabase db = dbOpenHelper.getWritableDatabase();
 *     db.execSQL("UPDATE person SET name = ?,phone = ? WHERE personid = ?",
 *         new String[]{p.getName(),p.getPhone(),p.getId()});
 * }
 * 4.查询数据：
 * public Person find(Integer id)
 * {
 *     SQLiteDatabase db = dbOpenHelper.getReadableDatabase();
 *     Cursor cursor =  db.rawQuery("SELECT * FROM person WHERE personid = ?",
 *             new String[]{id.toString()});
 *     //存在数据才返回true
 *     if(cursor.moveToFirst())
 *     {
 *         int personid = cursor.getInt(cursor.getColumnIndex("personid"));
 *         String name = cursor.getString(cursor.getColumnIndex("name"));
 *         String phone = cursor.getString(cursor.getColumnIndex("phone"));
 *         return new Person(personid,name,phone);
 *     }
 *     cursor.close();
 *     return null;
 * }
 * 5.数据分页：
 * public List<Person> getScrollData(int offset,int maxResult)
 * {
 *     List<Person> person = new ArrayList<Person>();
 *     SQLiteDatabase db = dbOpenHelper.getReadableDatabase();
 *     Cursor cursor =  db.rawQuery("SELECT * FROM person ORDER BY personid ASC LIMIT= ?,?",
 *         new String[]{String.valueOf(offset),String.valueOf(maxResult)});
 *     while(cursor.moveToNext())
 *     {
 *         int personid = cursor.getInt(cursor.getColumnIndex("personid"));
 *         String name = cursor.getString(cursor.getColumnIndex("name"));
 *         String phone = cursor.getString(cursor.getColumnIndex("phone"));
 *         person.add(new Person(personid,name,phone)) ;
 *     }
 *     cursor.close();
 *     return person;
 * }
 * 6.查询记录数：
 * public long getCount()
 * {
 *     SQLiteDatabase db = dbOpenHelper.getReadableDatabase();
 *     Cursor cursor =  db.rawQuery("SELECT COUNT (*) FROM person",null);
 *     cursor.moveToFirst();
 *     long result = cursor.getLong(0);
 *     cursor.close();
 *     return result;
 * }
 */