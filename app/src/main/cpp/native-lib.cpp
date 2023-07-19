#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_tesla_easyso2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

void on(JNIEnv *env, jobject thiz, jobject saved_instance_state) {
//    super.onCreate(savedInstanceState);
    jclass AppCompatActivity_1 = env->FindClass("androidx/appcompat/app/AppCompatActivity");
    jclass MainActivity_1 = env->FindClass("com/tesla/easyso2/MainActivity");
    jclass MainActivity_2 = env->GetObjectClass(thiz);
    jclass AppCompatActivity_2 = env->GetSuperclass(MainActivity_1);
    jmethodID onCreate_ = env->GetMethodID(AppCompatActivity_1, "onCreate",
                                           "(Landroid/os/Bundle;)V");
    env->CallNonvirtualVoidMethod(thiz, AppCompatActivity_1, onCreate_, saved_instance_state);

//    setContentView(R.layout.activity_main);
    jclass R$layout_ = env->FindClass("com/tesla/easyso2/R$layout");  // jadx-gui看smali
    jfieldID activity_main_ = env->GetStaticFieldID(R$layout_, "activity_main", "I");
    jint activity_main = env->GetStaticIntField(R$layout_, activity_main_);

    jmethodID setContentView_ = env->GetMethodID(AppCompatActivity_1, "setContentView", "(I)V");
    env->CallVoidMethod(thiz, setContentView_, activity_main);

//    TextView tv = findViewById(R.id.sample_text);
    jclass R$id_ = env->FindClass("com/tesla/easyso2/R$id");  // jadx-gui看smali
    jfieldID sample_text_ = env->GetStaticFieldID(R$id_, "sample_text", "I");
    jint sample_text = env->GetStaticIntField(R$id_, sample_text_);

    jmethodID findViewById_ = env->GetMethodID(AppCompatActivity_1, "findViewById",
                                               "(I)Landroid/view/View;");
    jobject tv = env->CallObjectMethod(thiz, findViewById_, sample_text);

//    tv.setText("easyso2");
    jclass TextView_ = env->FindClass("android/widget/TextView");
    jmethodID setText_ = env->GetMethodID(TextView_, "setText", "(Ljava/lang/CharSequence;)V");
    jstring hello = env->NewStringUTF("easyso2");
    env->CallVoidMethod(tv, setText_, hello);
}

JNINativeMethod nativeMethod[] = {
        {"onCreate", "(Landroid/os/Bundle;)V", (void *) on},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) (&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass MainActivity = env->FindClass("com/tesla/easyso2/MainActivity");
    if (env->RegisterNatives(MainActivity, nativeMethod,
                             sizeof(nativeMethod) / sizeof(nativeMethod[0])) != JNI_OK) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}