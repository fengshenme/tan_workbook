package com.example.android_demo.j.netlunbotu;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import com.example.android_demo.R;

import java.util.ArrayList;
import java.util.List;

public class LunBoTuActivity extends AppCompatActivity {

    private RadioGroup mRg_main;
    private List<BaseFragment> mBaseFragment;
    /**
     * 选中的Fragment的对应的位置
     */
    private int position;

    /**
     * 上次切换的Fragment
     */
    private Fragment mContent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lun_bo_to);
        mRg_main = findViewById(R.id.rg_main);
        //初始化Fragment
        mBaseFragment = new ArrayList<>();
        mBaseFragment.add(new HomeFrameFragment());//首页Fragment
        mBaseFragment.add(new ThirdPartyFragment());//第三方Fragment
        //设置RadioGroup的监听
        setListener();
        // 初始化标题栏

        initActionBar();
        if (Build.VERSION.SDK_INT >= 23) {
            int REQUEST_CODE_CONTACT = 101;
            final String[] permissions = {
                    Manifest.permission.WRITE_EXTERNAL_STORAGE,
                    Manifest.permission.READ_SMS,
                    Manifest.permission.INTERNET,
                    Manifest.permission.ACCESS_COARSE_LOCATION,
                    Manifest.permission.READ_PHONE_STATE,
                    Manifest.permission.RECORD_AUDIO,
                    Manifest.permission.READ_CONTACTS,
                    Manifest.permission.CALL_PHONE,
                    Manifest.permission.SYSTEM_ALERT_WINDOW,
                    Manifest.permission.WRITE_CONTACTS,
                    Manifest.permission.VIBRATE,
                    Manifest.permission.CAMERA
            };
            //验证是否许可权限
            for (String str : permissions) {
                if (this.checkSelfPermission(str) != PackageManager.PERMISSION_GRANTED) {
                    //申请权限
                    ActivityCompat.requestPermissions(this,permissions,REQUEST_CODE_CONTACT);
                    return;
                }
            }
        }

    }

    public void initActionBar() {
        Toolbar toolbar = (Toolbar) findViewById(R.id.activity_main_toolbar);
        toolbar.setTitle("题目");
        toolbar.setLogo(R.drawable.ab_android);
        toolbar.setSubtitle("副标题");
        setSupportActionBar(toolbar);
        toolbar.setNavigationIcon(R.drawable.back_mtrl_am_alpha);
        toolbar.setNavigationOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
        toolbar.setOnMenuItemClickListener(onMenuItemClick);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
    private Toolbar.OnMenuItemClickListener onMenuItemClick = new Toolbar.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                String msg = "";
                switch (item.getItemId()) {
                    case R.id.action_edit:
                        msg = "Click edit";
                        break;
                    case R.id.action_share:
                        msg = "Click share";
                        break;
                    case R.id.action_settings:
                        msg = "Click setting";
                        break;
                }
                if (!msg.equals("")) {
                    Toast.makeText(LunBoTuActivity.this, msg, Toast.LENGTH_SHORT).show();
                }
                return true;
            }
        };

    private void setListener() {
        mRg_main.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.rb_thirdparty://第三方
                        position = 1;
                        break;
                    default:
                        position = 0;//首页
                        break;
                }
                //根据位置得到对应的Fragment
                BaseFragment to = mBaseFragment.get(position);
                //替换
                switchFrament(mContent, to);
            }
        });
        //设置默认选中常用框架
        mRg_main.check(R.id.rb_common_frame);
    }

    private final FragmentManager fragmentManager = getSupportFragmentManager();

    /**
     *
     * @param from 刚显示的Fragment,马上就要被隐藏了
     * @param to 马上要切换到的Fragment，一会要显示
     */
    private void switchFrament(Fragment from, Fragment to) {
        if(from != to){
            mContent = to;
            FragmentTransaction ft = fragmentManager.beginTransaction();
            //才切换
            //判断有没有被添加
            if(!to.isAdded()){
                //to没有被添加
                //from隐藏
                if(from != null){
                    ft.hide(from);
                }
                //添加to
                if(to != null){
                    ft.add(R.id.fl_content,to).commit();
                }
            }else{
                //to已经被添加
                // from隐藏
                if(from != null){
                    ft.hide(from);
                }
                //显示to
                if(to != null){
                    ft.show(to).commit();
                }
            }
        }

    }

}
