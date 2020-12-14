// Trabalho da materia de Topicos Especiais em Integração Hardware e Software
// Requisito Integral para obtenção da M3
// autores: Paulo H Trindade
//          Bruna Rebello
//			Antonio Carlos 


#include "test.h"


using namespace std;

void test_control::do_test() 
{
	while (true) {

		rst = 0x1;
		inst = 0x9;
		print();
		wait(1);


		rst = 0x1;
		inst = 0x5;
		print();
		wait(1);


		rst = 0x0;
		inst = 0x23;
		print();
		wait(1);


		rst = 0x1;
		inst = 0x2B;
		print();
		wait(1);


		rst = 0x1;
		inst = 0x2;
		print();
		wait(1);


		rst = 0x0;
		inst = 0x8a;
		print();
		wait(1);


		rst = 0x0;
		inst = 0x2f;
		print();
		wait(1);


		rst = 0x0;
		inst = 0xfd;
		print();
		wait(1);


		rst = 0x0;
		inst = 0x7;
		print();
		wait();

	
	}
}

void test_control::print() {
	cout << "\t_________________________"
		<<"\n\n\t| Tempo --------> " << sc_time_stamp() << "|\n\t|\t\t\t|" 
		<< "\n\t| RESET:\t" << rst          <<"       |"
		<< "\n\t| INSTR:\t" << inst         << "  |"
		<< "\n\t| REGDST:\t" << regdstF     << "       |"
		<< "\n\t| JUMP:\t\t" << jumpF       << "       |"
		<< "\n\t| BRANCH:\t" << branchF     << "       |"
		<< "\n\t| MEMREAD:\t" << memreadF   << "       |"
		<< "\n\t| MEMTOREG:\t" << memtoregF << "       |"
		<< "\n\t| MEMWRITE:\t" << memwriteF << "       |"
		<< "\n\t| ALUSRC:\t" << alusrcF     << "       |"
		<< "\n\t| REGWRITE:\t" << regwriteF << "       |"
		<< "\n\t| ALUOP:\t" << aluopF       << "      |\n"
		<< "\t_________________________"
		<< "\n\n";

}
