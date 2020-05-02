package com.example.android_demo.j.netlunbotu;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;


public interface OkhttpService {

    /**
     *获取首页轮播图地址
     * @param filetype
     * @return
     */
    @GET("img/indeximg/{filetype}")
    Call<List<String>> getImageId(@Path("filetype") Integer filetype);

    @GET("img/file/{imgid}")
    Call<String> getImage(@Path("filetype") String imgid);


}
