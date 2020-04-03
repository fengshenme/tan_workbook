package com.example.demoone.g.utils;

import android.util.Log;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Created by Jay on 2015/9/2 0002.
 */
public class MD5 {

    public static String getMD5(String content) {
        try {
            MessageDigest digest = MessageDigest.getInstance("MD5");
            digest.update(content.getBytes());
            return getHashString(digest);
        } catch (NoSuchAlgorithmException e) {

            e.printStackTrace();
        }
        return null;
    }

    /**
     * 转换为十六进制字符串
     * @param digest
     * @return
     */
    private static String getHashString(MessageDigest digest) {
        StringBuilder builder = new StringBuilder();
        // 转换字节数组为十六进制字符串
        for (byte b : digest.digest()) {
            builder.append(Integer.toHexString((b >> 4) & 0xf));
            builder.append(Integer.toHexString(b & 0xf));
        }
        return builder.toString();
    }

    /**
     * md5加密10回
     * @param content
     * @return
     */
    public static String getMD5x10(String content){
        String s1 = content;
        for(int i = 0;i < 10;i++){
            s1 = getMD5(s1);
        }
        return s1;
    }
}
