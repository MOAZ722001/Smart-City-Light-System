// تعريف المنافذ
const int ldrPin = A0;    // منفذ LDR
const int ledPin1 = 2;    // منفذ LED 1
const int ledPin2 = 3;    // منفذ LED 2
const int ledPin3 = 4;    // منفذ LED 3

// تعريف المتغيرات
int ldrValue = 0;         // قيمة قراءة LDR

void setup() {
  // تهيئة المنافذ
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ldrPin, INPUT);

  // بدء الاتصال التسلسلي (للمراقبة)
  Serial.begin(9600);
}

void loop() {
  // قراءة قيمة LDR
  ldrValue = analogRead(ldrPin);

  // طباعة قيمة LDR للتحقق (اختياري)
  Serial.println(ldrValue);

  // التحكم في المصابيح بناءً على قيمة LDR
  if (ldrValue < 500) {  // إذا كانت الإضاءة منخفضة (ليل)
    digitalWrite(ledPin1, HIGH);  // تشغيل LED 1
    digitalWrite(ledPin2, HIGH);  // تشغيل LED 2
    digitalWrite(ledPin3, HIGH);  // تشغيل LED 3
  } else {  // إذا كانت الإضاءة كافية (نهار)
    digitalWrite(ledPin1, LOW);   // إطفاء LED 1
    digitalWrite(ledPin2, LOW);   // إطفاء LED 2
    digitalWrite(ledPin3, LOW);   // إطفاء LED 3
  }

  // تأخير بسيط لتجنب التحديث السريع
  delay(100);
}