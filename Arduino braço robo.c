//Quartz Mini Robotic ARM – Código de teste  

//Joystick 1 e 2 estão conectados em A0,A1, A2 e A3

// CONEXÕES SERVO

//Neck sero - D10 - pos é salvo na EEPROM 3

//Frente e Verso - D11 - pos é salvo na EEPROM 2

//UP e Down - D9 - pos é salvo na EEPROM 1

//Gripper - D6 - pos é salvo na EEPROM 0

//criado por: Aswinth Raj

//criado para: quartzcomponents.com

#include <Servo.h>

#include <EEPROM.h>

//Todas as posições da garra serão salvas e lidas no eeprom para retomar a mesma posição

int pinça_pos = EEPROM.read(0);

int updown_pos=EEPROM.read(1);

int frontback_pos=EEPROM.read(2);

int neck_pos = EEPROM.read(3);

// Cria um objeto servo - um para cada 4 servos

Garra Servo_servo;

ServoUpDown_servo;

Servo FrontBack_servo;

Servo Pescoço_servo;

//Funciona o controle do servo com base na posição do joystick

void control_servo (Servo & current_servo, int current_pos, int EEPROM_addr)

{

    //posição sempre deve estar entre 0 e 180

    se (pos_atual>=180)

    pos_atual=175; //jitter no limite máximo

    se (pos_atual<=0)

    posição_atual=10; //jitter no limite mínimo

    atual_servo.write(atual_pos); //atualiza a posição do servo

    EEPROM.write(EEPROM_addr, current_pos); //salva a posição na EEPROM

    Serial.print(EEPROM_addr); Serial.print(" = "); Serial.println(pos_atual); //para depuração no monitor serial

}

configuração vazia() {

  Serial.begin (9600);

  Garra_servo.attach(6);

  Gripper_servo.write(gripper_pos);

  UpDown_servo.attach(9);

  UpDown_servo.write(gripper_pos);

  FrontBack_servo.attach(11);

  FrontBack_servo.write(gripper_pos);

  Neck_servo.attach(10);

  Neck_servo.write(gripper_pos);

}

loop vazio() {

  ////USE PARA DEPURAÇÃO

  Serial.println ("Gripper, UpDown, FrontBack, Neck");

  Serial.print(gripper_pos);Serial.print(",");

  Serial.print(updown_pos);Serial.print(",");

  Serial.print(frontback_pos);Serial.print(",");

  Serial.print(pescoço_pos);Serial.println(".");*/

  atraso(50); //atraso predefinido para fazer o servo se mover mais devagar

//A0 para controlar o Gripper Servo

  int Joy_value_X1 = analogRead (A0);

  se (Joy_value_X1 > 700){

    pinça_pos = pinça_pos + 1;

    control_servo (Gripper_servo, grip_pos, 0);

  }

  if (Joy_value_X1 <300){

    pinça_pos = pinça_pos - 1;

    control_servo (Gripper_servo, grip_pos, 0);

  }

//A1 para controlar o UpDown Servo

    int Joy_value_Y1 = analogRead (A1);

  se (Joy_value_Y1 > 700){

    updown_pos = updown_pos + 1;

    control_servo (UpDown_servo, updown_pos, 1);

  }

  if (Joy_value_Y1 <300){

    updown_pos = updown_pos - 1;

    control_servo (UpDown_servo, updown_pos, 1);

  }

//A2 para controlar o FrontBack Servo

      int Joy_value_X2 = analogRead (A2);

  se (Joy_value_X2 > 700){

    frontback_pos = frontback_pos + 1;

    control_servo (FrontBack_servo, frontback_pos, 2);

  }

  if (Joy_value_X2 <300){

    frontback_pos = frontback_pos - 1;

    control_servo (FrontBack_servo, frontback_pos, 2);

  }

//A3 para controlar o Neck Servo

        int Joy_value_Y2 = analogRead (A3);

  se (Joy_value_Y2 > 700){

    pescoço_pos = pescoço_pos + 1;

    control_servo (pescoço_servo, pescoço_pos, 3);

  }

  if (Joy_value_Y2 <300){

    pescoço_pos = pescoço_pos - 1;

    control_servo (pescoço_servo, pescoço_pos, 3);

  }

}