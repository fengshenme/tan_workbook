#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

char *_JString2CStr(JNIEnv* env,jstring pJstring);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_android_1demo_j_JNI_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/**
 * 让C代码调用 java 中JNI类的 public int add(int x, int y)
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JNI_callbackAdd(JNIEnv *env, jobject thiz){

//1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("com/example/android_demo/j/JNI");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= (env)->GetMethodID(jclazz,"add","(II)I");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject  jobject =(env)->AllocObject(jclazz);
    //4.调用方法
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint value =  (env)->CallIntMethod(jobject,jmethodIDs,99,1);
    //成功调用了public int add(int x, int y)
    printf("value===%d\n",value);
    LOGE("value===%d\n",value);

};

/**
 * 让C代码调用
     * public void helloFromJava()
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JNI_callbackHelloFromJava (JNIEnv *env, jobject thiz)
{

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (env)->FindClass("com/example/android_demo/j/JNI");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= (env)->GetMethodID(jclazz,"helloFromJava","()V");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject  jobject =(env)->AllocObject(jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (env)->CallVoidMethod(jobject,jmethodIDs);
    //成功调用了public void helloFromJava()

};

/**
 * 让C代码调用void printString(String s)
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JNI_callbackPrintString(JNIEnv *env, jobject thiz) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (env)->FindClass("com/example/android_demo/j/JNI");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= (env)->GetMethodID(jclazz,"printString","(Ljava/lang/String;)V");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject  jobject =(env)->AllocObject(jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring jst = (env)->NewStringUTF("I am afu!!!(*env)->");
    (env)->CallVoidMethod(jobject,jmethodIDs,jst);
    //成功调用了public void helloFromJava()
};

/**
 * 让C代码静态方法 static void sayHello(String s)
 */
extern "C" JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JNI_callbackSayHello(JNIEnv *env, jobject thiz) {
    // TODO: implement callbackSayHello()
    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (env)->FindClass("com/example/android_demo/j/JNI");
    //2.得到方法
    //jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= (env)->GetStaticMethodID(jclazz,"sayHello","(Ljava/lang/String;)V");
    //3.实例化该类
    //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    jstring jst = (env)->NewStringUTF("I am android1223");
    (env)->CallStaticVoidMethod(jclazz,jmethodIDs,jst);
    //成功调用了static void sayHello(String s)
}

/**
 * 给每个元素加10
 */
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_example_android_1demo_j_JNI_increaseArrayEles(JNIEnv *env, jobject thiz, jintArray jarray) {
    // TODO: implement increaseArrayEles()
    // 得到数组的长度
    jsize size = env -> GetArrayLength(jarray);
    // 得到数组元素
    jint* intArray = env -> GetIntArrayElements(jarray,JNI_FALSE);
    // 遍历数组给其中元素加10
    int i;
    for (i = 0; i < size; ++i) {
        *(intArray + i) += 10;
    }
    return jarray;
}


extern "C" JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JniActivity_call(JNIEnv *env, jobject instace) {

}


//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_example_jnidemo1_jni_JNI_stringFromJNI(JNIEnv *env, jobject thiz) {
//    // TODO: implement stringFromJNI()
//
//    char* text = const_cast<char *>("Hello from C++ a----");
//
//    return env -> NewStringUTF(text);
//}

/**
 * 密码校对
 */
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_android_1demo_j_JNI_checkPwd(JNIEnv *env, jobject thiz, jstring pwd) {
    // TODO: implement checkPwd()

    // 服务器密码123456
    char const* origin = "123456";
    char* fromUser = _JString2CStr(env,pwd);
    int code = strcmp(origin,fromUser);
    if(code ==0){
        return 200;
    } else {
        return 400;
    }
}


/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char *_JString2CStr(JNIEnv* env,jstring pJstring) {
    char* rtn = NULL;
    jclass clsstring = (env)->FindClass("java/lang/String");
    jstring strencode = (env)->NewStringUTF("UTF-8");
    jmethodID mid = (env)->GetMethodID( clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(env)->CallObjectMethod( pJstring, mid, strencode); // String .getByte("GB2312");
    jsize alen = (env)->GetArrayLength( barr);
    jbyte* ba = (env)->GetByteArrayElements(barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (env)->ReleaseByteArrayElements(barr, ba,0);
    return rtn;
}

/**
 * instance:谁调用了当前Java_com_example_android_1demo_j_JniActivity_callBackShowToast对应的Java的接口
 * 就是谁的实例：当前是JNI.this-->JniActivity.this
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_example_android_1demo_j_JniActivity_callBackShowToast(JNIEnv *env, jobject instace) {
    // TODO: implement callBackShowToast()

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("com/example/android_demo/j/JniActivity");
    //2.得到方法
    //最后一个参数是方法签名
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodIDs= (env)->GetMethodID(jclazz,"showToast", "()V");
    //3.实例化该类
    //   jobject     (*AllocObject)(JNIEnv*, jclass);
    //jobject  jobject1 = (*env)->AllocObject(env,jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (env)->CallVoidMethod(instace,jmethodIDs);
    //成功调用了static void sayHello(String s)
}