// Trabalho da materia de Topicos Especiais em Integração Hardware e Software
// Requisito Integral para obtenção da M3
// autores: Paulo H Trindade
//          Bruna Rebello
//			Antonio Carlos 


#pragma once
#include "mips.h"

SC_MODULE(test_control) {
		sc_in<bool> clock;
		sc_out <sc_bv<1> >	rst;
		sc_out <sc_bv<6> >	inst;
		sc_in  <sc_bv<1> >	regdstF;
		sc_in  <sc_bv<1> >	jumpF;
		sc_in  <sc_bv<1> >	branchF;
		sc_in  <sc_bv<1> >	memreadF;
		sc_in  <sc_bv<1> >	memtoregF;
		sc_in  <sc_bv<1> >	memwriteF;
		sc_in  <sc_bv<1> >	alusrcF;
		sc_in  <sc_bv<1> >	regwriteF;
		sc_in  <sc_bv<2> >	aluopF;

	void do_test();

	void print();

	SC_CTOR(test_control) {
		SC_CTHREAD(do_test, clock.pos());
	}
};