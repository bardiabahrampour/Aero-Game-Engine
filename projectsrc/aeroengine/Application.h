#pragma once
#include "AlphaRender.h"
#include <chaiscript/chaiscript.hpp>
namespace App {


	class Engine {
		

	private:

		chaiscript::ChaiScript ChaiStart;

		std::string ScriptPath{ "test.chai" };


	public:

		void InitScripts(void);
		void start(void);
		void StartScript(void);
	};






}





