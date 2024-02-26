/*
 * Timer.h
 *
 * Created: 11/16/2021 6:11:35 PM
 *  Author: "Lankash"
 */ 


#ifndef TIMER_H_              //File Guard
#define TIMER_H_
 
 //................................................................


/*
    Function name         :  Timer_CTC_init_interrupt
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar.
    Function Description  :  Initialize the Timer in "CTC Interrupt" Mode.
*/
void Timer0_CTC_init_interrupt (unsigned char OCR0_val, unsigned short prescalar);


/*
    Function name         :  Timer_wave_nonPWM_OC0
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC0'.
*/
void Timer0_wave_nonPWM (unsigned char OCR0_val, unsigned short prescalar);


/*
    Function name         :  Timer0_fastpwm
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar, unsigned char inverting.
    Function Description  :  Generate PWM waveform on pin 'OC0'.
	COM Mode              :  0 >> Non-Inverting - Clear on compare - Set at bottom
	                         1 >> Inverting     - Set on compare   - Clear at bottom
*/
void Timer0_fastPWM (unsigned char OCR0_val, unsigned short prescalar, unsigned char inverting);

/*
    Function name         :  Timer0_phase_correct_pwm
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar, unsigned char oc0_mode.
    Function Description  :  Generate PWM waveform on pin 'OC0'.
	COM Mode              :  0 >> Clear on compare Up_Counting - Set on compare Down_Counting
	                         1 >> Set on compare Up_Counting  - Clear on compare Down_Counting
*/
void Timer0_phase_correct_pwm (unsigned char OCR0_val, unsigned short prescalar, unsigned char oc0_mode);


/*
    Function name         :  Timer_wave_nonPWM_OC1A
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR1A_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC1A'.
*/
void Timer1A_wave_nonPWM (unsigned char OCR1A_val, unsigned short prescalar);


/*
    Function name         :  Timer_wave_nonPWM_OC1B
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR1B_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC1B'.
*/
void Timer1B_wave_nonPWM (unsigned char OCR1B_val, unsigned short prescalar);


/*
    Function name         :  Timer2_CTC_init_interrupt
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar.
    Function Description  :  Generates Clear timer on compare interrupt. 
*/
void Timer2_CTC_init_interrupt (unsigned char OCR2_val, unsigned short prescalar);


/*
    Function name         :  Timer_wave_nonPWM_OC2
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC2'.
*/
void Timer2_wave_nonPWM (unsigned char OCR2_val, unsigned short prescalar);


/*
    Function name         :  Timer_fastPWM_OC2
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar, unsigned char inverting.
    Function Description  :  Generate PWM waveform, Inverting @(inverting=1), Non-Inverting @(inverting=0)
*/
void Timer2_fastPWM (unsigned char OCR2_val, unsigned short prescalar, unsigned char inverting);


/*
    Function name         :  Timer2_phase_correct_pwm
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar, unsigned char OC0_mode.
    Function Description  :  Function Description  :  Generate PWM waveform on pin 'OC0'.
    COM Mode              :  0 >> Clear on compare Up_Counting - Set on compare Down_Counting
                             1 >> Set on compare Up_Counting  - Clear on compare Down_Counting
*/
void Timer2_phase_correct_pwm (unsigned char OCR2_val, unsigned short prescalar, unsigned char OC0_mode);

#endif /* TIMER_H_ */