package com.tesla.easyso2;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'easyso2' library on application startup.
    static {
        System.loadLibrary("easyso2");
    }

//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//
//        // Example of a call to a native method
//        TextView tv = findViewById(R.id.sample_text);
//        tv.setText("easyso2");
//    }

    /**
     * A native method that is implemented by the 'easyso2' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void onCreate(Bundle savedInstanceState);
}