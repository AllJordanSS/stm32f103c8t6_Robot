// robot_types.h

#ifndef ROBOT_TYPES_H
#define ROBOT_TYPES_H

#include "main.h"

// -----------------------------------------------------------
// C. Estruturas de Dados Compartilhadas (Página 3 do Documento)
// -----------------------------------------------------------

// 1. RC_DATA_STRUCT: Dados brutos dos 16 canais RC
typedef struct {
    uint16_t channel[16];   // Valores brutos, tipicamente 1000 a 2000
} RC_Data_t;
extern RC_Data_t RC_Data; // Variável global de dados

// 2. SYSTEM_STATE_STRUCT: Estado de operação
typedef enum {
    MODE_MANUAL,        // Controle via RC
    MODE_AUTONOMOUS,    // Controle via ROS/CmdVel
} System_Mode_t;

typedef struct {
    System_Mode_t current_mode;
    uint8_t is_armed;           // 0: Desarmado, 1: Armado (Segurança)
} System_State_t;
extern System_State_t System_State;

// 3. CMD_VEL_STRUCT: Alvo de Velocidade de alto nível (ROS)
typedef struct {
    float linear_x;     // Velocidade linear (m/s)
    float angular_z;    // Velocidade angular (rad/s)
} CmdVel_Target_t;
extern CmdVel_Target_t CmdVel_Target;

// 4. MOTOR_TARGET_STRUCT: Alvo de Velocidade de baixo nível (PID)
typedef struct {
    float omega_right;  // Velocidade angular da Roda Direita (rad/s)
    float omega_left;   // Velocidade angular da Roda Esquerda (rad/s)
} Motor_Target_t;
extern Motor_Target_t Motor_Target;

// 5. ENCODER_STRUCT: Feedback de velocidade e odometria
typedef struct {
    int32_t count_r;    // Contagem absoluta do Encoder Direito
    int32_t count_l;    // Contagem absoluta do Encoder Esquerdo
    float speed_r;      // Velocidade angular da Roda Direita (rad/s)
    float speed_l;      // Velocidade angular da Roda Esquerda (rad/s)
} Encoder_Data_t;
extern Encoder_Data_t Encoder_Data;

#endif // ROBOT_TYPES_H
