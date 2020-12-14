// Trabalho da materia de Topicos Especiais em Integração Hardware e Software
// Requisito Integral para obtenção da M3
// autores: Paulo H Trindade
//          Bruna Rebello
//			Antonio Carlos 


#include "mips.h"

#include "control.h"

#include "test.h"

int sc_main(int argc, char* argv[]) {

	sc_clock CLK("clock", 50, SC_NS);

	sc_signal  <sc_bv<1> >		rst;
	sc_signal  <sc_bv<6> >		inst;
	sc_signal  <sc_bv<1> >		regdstF;
	sc_signal  <sc_bv<1> >		jumpF;
	sc_signal  <sc_bv<1> >		branchF;
	sc_signal  <sc_bv<1> >		memreadF;
	sc_signal  <sc_bv<1> >		memtoregF;
	sc_signal  <sc_bv<1> >		memwriteF;
	sc_signal  <sc_bv<1> >		alusrcF;
	sc_signal  <sc_bv<1> >		regwriteF;
	sc_signal  <sc_bv<2> >		aluopF;
	
	CONTROL CONTROL("CONTROL");
	
	CONTROL(rst, inst, regdstF, jumpF, branchF, memreadF, memtoregF, memwriteF, alusrcF, regwriteF, aluopF);

	test_control TESTCONTROL("TESTCONTROL");
	
	TESTCONTROL(CLK, rst, inst, regdstF, jumpF, branchF, memreadF, memtoregF, memwriteF, alusrcF, regwriteF, aluopF);

	sc_start(500, SC_NS);

	return(0);
}
