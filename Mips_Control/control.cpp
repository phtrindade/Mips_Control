// Trabalho da materia de Topicos Especiais em Integração Hardware e Software
// Requisito Integral para obtenção da M3
// autores: Paulo H Trindade
//          Bruna Rebello
//			Antonio Carlos 



#include "control.h"
 
void CONTROL::control()
{
	sc_bv<1>	rst;
	sc_uint<6>	inst;
	sc_bv<1>	regdstF;
	sc_bv<1>	jumpF;
	sc_bv<1> 	branchF;
	sc_bv<1> 	memreadF;
	sc_bv<1> 	memtoregF;
	sc_bv<1> 	memwriteF;
	sc_bv<1> 	alusrcF;
	sc_bv<1> 	regwriteF;
	sc_bv<2> 	aluopF;


	rst = reset.read();
	
	inst = instruction.read();
	

	if(rst == 1) {
		regdstF = 0x0;
		jumpF = 0x0;
		branchF = 0x0;
		memreadF = 0x0;
		memtoregF = 0x0; 
		memwriteF = 0x0; 
		alusrcF = 0x0;
		regwriteF = 0x0;
		aluopF = 0x0;
	} else {
		switch(inst) {
			// INSTRUCTION R
			case 0x0:
				regdstF = 0x1;
				jumpF = 0x0;
				branchF = 0x0;
				memreadF = 0x0;
				memtoregF = 0x0; 
				memwriteF = 0x0;
				alusrcF = 0x0;
				regwriteF = 0x1; 
				aluopF = 0x2;
				break;
			// INSTRUCTION LW
			case 0x23:
				regdstF = 0x0;
				jumpF = 0x0;
				branchF = 0x0;
				memreadF = 0x1;
				memtoregF = 0x1; 
				memwriteF = 0x0; 
				alusrcF = 0x1; 
				regwriteF = 0x1; 
				aluopF = 0x0;
				break;
			// INSTRUCTION SW
			case 0x2B:
				regdstF = 0x0; 
				jumpF = 0x0; 
				branchF = 0x0;
				memreadF = 0x0; 
				memtoregF = 0x0; 
				memwriteF = 0x1; 
				alusrcF = 0x1; 
				regwriteF = 0x0; 
				aluopF = 0x0;
				break;
			// INSTRUCTION JUMP
			case 0x2:
				regdstF = 0x0; 
				jumpF = 0x1; 
				branchF = 0x0; 
				memreadF = 0x0; 
				memtoregF = 0x0; 
				memwriteF = 0x0; 
				alusrcF = 0x0; 
				regwriteF = 0x0; 
				aluopF = 0x0;
				break;
			// INSTRUCTION ADDI
			case 0x8:
				regdstF = 0x0; 
				jumpF = 0x0;
				branchF = 0x0;
				memreadF = 0x0; 
				memtoregF = 0x0; 
				memwriteF = 0x0; 
				alusrcF = 0x1; 
				regwriteF = 0x1; 
				aluopF = 0x0;
				break;
			// INSTRUCTION LUI
			case 0xF: 
				regdstF = 0x0; 
				jumpF = 0x0; 
				branchF = 0x0; 
				memreadF = 0x0;
				memtoregF = 0x0; 
				memwriteF = 0x0;
				alusrcF = 0x1;
				regwriteF = 0x1;
				aluopF = 0x2;
				break;
			// INSTRUCTION ORI
			case 0xD:
				regdstF = 0x0; 
				jumpF = 0x0; 
				branchF = 0x0; 
				memreadF = 0x0;
				memtoregF = 0x0; 
				memwriteF = 0x0;
				alusrcF = 0x1; 
				regwriteF = 0x1;
				aluopF = 0x2;
				break;
			// INSTRUCTION BEQ
			case 0x4:
				regdstF = 0x0;
				jumpF = 0x0; 
				branchF = 0x1;
				memreadF = 0x0;
				memtoregF = 0x0; 
				memwriteF = 0x0;
				alusrcF = 0x0; 
				regwriteF = 0x0;
				aluopF = 0x2;
				break;
			default:
				regdstF = 0x0;
				jumpF = 0x0;
				branchF = 0x1;
				memreadF = 0x0; 
				memtoregF = 0x0; 
				memwriteF = 0x0;
				alusrcF = 0x0;
				regwriteF = 0x0;
				aluopF = 0x1;
				break;
		}
	}

	regdst.write(regdstF);		
	jump.write(jumpF);		
	branch.write(branchF);	
	memread.write(memreadF);	
	memtoreg.write(memtoregF);	
	memwrite.write(memwriteF);	
	alusrc.write(alusrcF);	
	regwrite.write(regwriteF);
	aluop.write(aluopF);	
}
