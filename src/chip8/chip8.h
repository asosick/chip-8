#ifndef CHIP_8_CHIP8_H
#define CHIP_8_CHIP8_H
#include "../types.h"

const u16 START_ADDRESS = 0x200;
const u16 FONTSET_SIZE = 80;
const u16 FONTSET_START_ADDRESS = 0x50;

class Chip8{
public:
    u8  registers[16]{};
    u8  memory[4096]{};
    u16 index{};
    u16 pc{};
    u16 stack[16]{};
    u8  sp{};
    u8  delay_timer{};
    u8  sound_timer{};
    u8  keypad[16];
    u32 video[64 * 32]{};
    u16 opcode;

    Chip8();

    void loadRom(const std::string filename);


//OPs
void OP_00E0_CLS();     /* CLS                 - Clear the display.                                                                    */
void OP_EE_RET();       /* RET                 - Return from a subroutine.                                                            */
void OP_1nnn_JP();      /* JP addr             - Jump to location nnn.                                                                */
void OP_2nnn_JP();      /* CALL addr           - Call subroutine at nnn                                                               */
void OP_3xkk_SE();      /* SE Vx, byte         - Skip next instruction if Vx = kk.                                                    */
void OP_4xkk_SNE();     /* SNE Vx, byte        - Skip next instruction if Vx != kk.                                                   */
void OP_5xy0_SE();      /* SE Vx, Vy           - Skip next instruction if Vx = Vy.                                                    */
void OP_6xkk_LD();      /* LD Vx, byte         - Set Vx = kk.                                                                         */
void OP_7xkk_ADD();     /* ADD Vx, byte        - Set Vx = Vx + kk.                                                                    */
void OP_8xy0_LD();      /* LD Vx, Vy           - Set Vx = Vy.                                                                         */
void OP_8xy1_OR();      /* OR Vx, Vy           - Set Vx = Vx OR Vy.                                                                   */
void OP_8xy2_AND();     /* AND Vx, Vy          - Set Vx = Vx AND Vy.                                                                  */
void OP_8xy3_XOR();     /* XOR Vx, Vy          - Set Vx = Vx XOR Vy.                                                                  */
void OP_8xy4_AND();     /* ADD Vx, Vy          - Set Vx = Vx + Vy, set VF = carry.                                                    */
void OP_8xy5_SUB();     /* SUB Vx, Vy          - Set Vx = Vx - Vy, set VF = NOT borrow.                                               */
void OP_8xy6_SHR();     /* SHR Vx {, Vy}       - Set Vx = Vx SHR 1.                                                                   */
void OP_8xy7_BN();      /* SUBN Vx, Vy         - Set Vx = Vy - Vx, set VF = NOT borrow.                                               */
void OP_8xyE_SHL();     /* SHL Vx {, Vy}       - Set Vx = Vx SHL 1.                                                                   */
void OP_9xy0_SNE();     /* SNE Vx, Vy          - Skip next instruction if Vx != Vy.                                                   */
void OP_Annn_LD();      /* LD I, addr          - Set I = nnn.                                                                         */
void OP_Bnnn_JP();      /* JP V0, addr         - Jump to location nnn + V0.                                                           */
void OP_Cxkk_RND();     /* RND Vx, byte        - Set Vx = random byte AND kk.                                                         */
void OP_Dxyn_DRW();     /* DRW Vx, Vy, nibble  - Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision. */
void OP_Ex9E_SKP();     /* SKP Vx              - Skip next instruction if key with the value of Vx is pressed.                        */
void OP_ExA1_SKNP();    /* SKNP Vx             - Skip next instruction if key with the value of Vx is not pressed.                    */
void OP_Fx07_LD();      /* LD Vx, DT           - Set Vx = delay timer value.                                                          */
void OP_Fx0A_LD();      /* LD Vx, K            - Wait for a key press, store the value of the key in Vx.                              */
void OP_Fx15_LD();      /* LD DT, Vx           - Set delay timer = Vx.                                                                */
void OP_Fx18_LD();      /* LD ST, Vx           - Set sound timer = Vx.                                                                */
void OP_Fx1E_ADD();     /* ADD I, Vx           - Set I = I + Vx.                                                                      */
void OP_Fx29_LD();      /* LD F, Vx            - Set I = location of sprite for digit Vx.                                             */
void OP_Fx33_LD();      /* LD B, Vx            - Store BCD representation of Vx in memory locations I, I+1, and I+2.                  */
void OP_Fx55_LD();      /* LD [I], Vx          - Store registers V0 through Vx in memory starting at location I.                      */
void OP_Fx65_LD();      /* LD Vx, [I]          - Read registers V0 through Vx from memory starting at location I.                     */

private:
    void loadFontSet();
};


u8 fontset[FONTSET_SIZE] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,       // 0
    0x20, 0x60, 0x20, 0x20, 0x70,       // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};



#endif //CHIP_8_CHIP8_H
