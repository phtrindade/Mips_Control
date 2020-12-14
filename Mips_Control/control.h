// Trabalho da materia de Topicos Especiais em Integração Hardware e Software
// Requisito Integral para obtenção da M3
// autores: Paulo H Trindade
//          Bruna Rebello
//			Antonio Carlos 


#include "mips.h"

SC_MODULE(CONTROL) {
	sc_in<	sc_bv<1> >		reset;
	sc_in<	sc_bv<6> >		instruction;
	sc_out< sc_bv<1> >		regdst;
	sc_out<	sc_bv<1> >		jump;
	sc_out< sc_bv<1> >		branch;
	sc_out< sc_bv<1> >		memread;
	sc_out< sc_bv<1> >		memtoreg;
	sc_out< sc_bv<1> >		memwrite;
	sc_out< sc_bv<1> >		alusrc;
	sc_out< sc_bv<1> >		regwrite;
	sc_out< sc_bv<2> >		aluop;

	void control();

	SC_CTOR(CONTROL) {
		SC_METHOD(control);
		sensitive << reset << instruction;
	}
};