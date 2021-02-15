
#ifndef STD_MACROS_H_
#define STD_MACROS_H_

/* Set a certain bit no. in a register to 1 */
#define SET_BIT(Reg, Bit) (Reg |= (1<<Bit))

/* Clear a certain bit no. in a register to 0 */
#define CLR_BIT(Reg, Bit) (Reg &= ~(1<<Bit))

/* Get the value of a certain bit no. in a register */
#define GET_BIT(Reg, Bit) ((Reg >> Bit) & 1)

/* Toggle a certain bit no. in a register to the opposite value */
#define TOGGLE_BIT(Reg, Bit) (Reg ^= (1<<Bit))

/* Shift left multiple bits in a register */
#define SHL_REG(Reg, Bit) (Reg <<= Bit)

/* Shift right multiple bits in a register */
#define SHR_REG(Reg, Bit) (Reg >>= Bit)

/* Set first (most significant) 4 bits to 1 */
#define SET_NIBBLE_H(Reg) (Reg |= 0xF0)

/* Clear first (most significant) 4 bits to 0 */
#define CLR_NIBBLE_H(Reg) (Reg &= 0x0F)

/* Set second (least significant) 4 bits to 1 */
#define SET_NIBBLE_L(REG) (REG |= 0x0F)

/* Clear second (least significant) 4 bits to 0 */
#define CLR_NIBBLE_L(Reg) (Reg &= 0xF0)

/* Get first (most significant) 4 bits value */
#define GET_NIBBLE_H(Reg) ((Reg >> 4) & 0x0F)

/* Get second (least significant) 4 bits value */
#define GET_NIBBLE_L(Reg) (Reg & 0x0F)

/* Assign first (most significant) 4 bits to a certain value */
#define ASSIGN_NIBBLE_H_VALUE(Reg, Value) (Reg = CLR_NIBBLE_H(Reg) + (Value<<4))

/* Assign second (least significant) 4 bits to a certain value */
#define ASSIGN_NIBBLE_L_VALUE(Reg, Value) (Reg = CLR_NIBBLE_L(Reg) + (Value))

/* Assign the whole register, with a certain value */
#define ASSIGN_REG_VALUE(Reg, Value) (Reg = Value)

#endif /* STD_MACROS_H_ */