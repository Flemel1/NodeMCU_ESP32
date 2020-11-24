package com.example.iotesp32firebase

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.iotesp32firebase.databinding.ActivityMainBinding
import com.google.firebase.database.*

class MainActivity : AppCompatActivity() {

    private lateinit var mBinding : ActivityMainBinding
    private lateinit var dbRef : DatabaseReference
    private var ldrValue = ""
    private var servoValue = ""
    private val pathLDR = "iot/ldr"
    private val pathServo = "iot/servo"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        mBinding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(mBinding.root)
        dbRef = FirebaseDatabase.getInstance().reference
        dbRef.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                ldrValue = snapshot.child(pathLDR).value.toString()
                mBinding.tvLdrValue.text = ldrValue
                servoValue = snapshot.child(pathServo).value.toString()
                mBinding.tvServoValue.text = servoValue
            }

            override fun onCancelled(error: DatabaseError) {

            }

        })
    }
}