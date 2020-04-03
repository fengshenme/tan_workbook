package com.example.demoone.f.my;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * Created by Jay on 2015/9/6 0006.
 */
public class Data implements Parcelable {

    private String new_title;
    private String new_content;

    public Data(){}

    public Data(String new_title, String new_content) {
        this.new_title = new_title;
        this.new_content = new_content;
    }

    protected Data(Parcel in) {
        new_title = in.readString();
        new_content = in.readString();
    }

    public static final Creator<Data> CREATOR = new Creator<Data>() {
        @Override
        public Data createFromParcel(Parcel in) {
            Data d = new Data();
            d.setNew_title(in.readString());
            d.setNew_content(in.readString());
            return d;
        }

        @Override
        public Data[] newArray(int size) {
            return new Data[size];
        }
    };

    public String getNew_title() {
        return new_title;
    }

    public String getNew_content() {
        return new_content;
    }

    public void setNew_title(String new_title) {
        this.new_title = new_title;
    }

    public void setNew_content(String new_content) {
        this.new_content = new_content;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(new_title);
        dest.writeString(new_content);

    }

    @Override
    public String toString() {
        return "Data{" +
                "new_title='" + new_title + '\'' +
                ", new_content='" + new_content + '\'' +
                '}';
    }
}
