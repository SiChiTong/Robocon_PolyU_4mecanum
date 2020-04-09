/*
README
*/

//**TYPE DEF
typedef enum NMT_COMMAND
{
    STOP = 0,
    SET_PREOP = 1,
    RESET_COMMU = 2,
    RESET_NODE = 3,
    SET_OP = 4
}NMT_COMMAND;

typedef enum CW_COMMAND
{
    SHUT_DOWN = 0,
    SWITCH_ON_ENABLE_OP = 1,
    DISABLE_OP = 2,
    QUICK_STOP = 3,
    CLEAR_FAULT = 4
}CW_COMMAND;

typedef enum OP_MODE
{
    IPM = 0x07,
    HM =  0x06,
    PVM = 0x03,
    PPM = 0x01,
    PM =  0xFF,
    VM =  0xFE, 
    CM =  0xFD,
    DM =  0xFC,  
    MEM = 0xFB,
    SDM = 0xFA
}OP_MODE;

typedef enum HOMING_MODE
{
    AP = 35,
    INS = 34,
    IPS = 33,
    CTPSI = -1,
    CTNSI = -2,
    CTPS = -3, 
    CTNS = -4
}HOMING_MODE;

typedef enum MOTION_PROFILE_TYPE
{
    LINEAR = 0,
    SIN = 1
}MOTION_PROFILE_TYPE;

typedef enum PDO_SEQUENCE
{
    RPDO1 = 0,
    RPDO2 = 1,
    RPDO3 = 2,
    RPDO4 = 3,
    TPDO1 = 0,
    TPDO2 = 1,
    TPDO3 = 2,
    TPDO4 = 3
}PDO_SEQUENCE;

typedef enum PDO_TRANSTYPE
{
    ASYNC = 255,
    RTR = 253,
    SYNC = 1
}PDO_TRANSTYPE;

//**FUNCTIONS DECLARATION
void SET_CANOpen_FREQ(int freq);

bool SET_NMT(NMT_COMMAND cmd);

void DATA2ARRAY(uint32_t data);
void DATA2ARRAY(int32_t data);

void SYNC_SEND();
void START_SYNC(float sync_interval);
void STOP_SYNC();

bool SDO_SEND(uint8_t node_num, const char* msg);
bool SDO_EXE(uint8_t node_num, char index_lower, char index_higher, char subindex, uint32_t data, char valid_data_length_in_byte);
bool SDO_EXE(uint8_t node_num, char index_lower, char index_higher, char subindex, int32_t data, char valid_data_length_in_byte);

bool SDO_CW(uint8_t node_num, CW_COMMAND cmd);

bool RPDO_CONFIG(uint8_t node_num, PDO_SEQUENCE seq, PDO_TRANSTYPE type);
//bool TPDO_CONFIG(uint8_t node_num, PDO_TRANSTYPE type);


//#######################################################################
//#                     USER DEFINED FUNCTIONS                          #
//#######################################################################


void CANOpen_SETUP(int freq, float sync_interval);
bool PDO_INIT();
bool PDO_SEND(uint8_t node_num, PDO_SEQUENCE seq, const char* msg, char length);
bool RPDO1_EXE(uint8_t node_num, CW_COMMAND cmd);
bool RPDO1_EXE(uint8_t node_num, uint16_t cwcommand);

void CAN_RECEIVE_INTERRUPT();

/*

class VESC{
public:
bool sendPacket(uint32_t id, uint8_t packet[], int32_t len);
void crossbow(uint8_t controller_id, float pos);
void buffer_append_int32(uint8_t* buffer, int32_t number, int32_t *index);
};

*/




