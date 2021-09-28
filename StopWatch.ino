int tenMilli = 0;
int hundredMilli = 0;
int second = 0;
int minutes = 0;
int hours = 0;
boolean start = false;
void setup ()
{
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B = B00001100;
    TIMSK1 = B00000010;
    OCR1A  = 625;

    attachInterrupt (0,starter,LOW);
    pinMode(2,INPUT_PULLUP);

    Serial.begin (115200);
}
ISR (TIMER1_COMPA_vect)
{
//    if (start == true)
//    {
        tenMilli++;
        if (tenMilli > 9)
        {
            tenMilli = 0;
            hundredMilli++;
            if(hundredMilli > 9)
            {
                hundredMilli = 0;
                second++;
                if (second > 59)
                {
                    second = 0;
                    minutes++;
                    if (minutes > 59)
                    {
                        minutes = 0;
                        hours++;
                    }
                }
            }
        }
//    }
    
}
void starter ()
{
    start = !start;
}
void loop ()
{
    Serial.println (String(hours)+" : "+String(minutes)+" : "+String(second)+" : "+String(hundredMilli)+String(tenMilli));
}
