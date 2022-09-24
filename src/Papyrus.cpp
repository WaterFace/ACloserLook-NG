#include "Papyrus.h"

#include "Events.h"
#include "LookHandler.h"

namespace Papyrus
{
	float ACloserLook::GetFOVDiff(RE::StaticFunctionTag*)
	{
		auto lookHandler = LookHandler::GetSingleton();
		return lookHandler->GetFOVDiff();
	}

	void ACloserLook::SetFOVDiff(RE::StaticFunctionTag*, float a_diff)
	{
		auto lookHandler = LookHandler::GetSingleton();
		lookHandler->SetFOVDiff(a_diff);
	}

	float ACloserLook::GetStep(RE::StaticFunctionTag*)
	{
		auto lookHandler = LookHandler::GetSingleton();
		return lookHandler->GetStep();
	}

	void ACloserLook::SetStep(RE::StaticFunctionTag*, float a_step)
	{
		auto lookHandler = LookHandler::GetSingleton();
		lookHandler->SetStep(a_step);
	}

	std::uint32_t ACloserLook::GetKey(RE::StaticFunctionTag*)
	{
		auto inputHandler = Events::InputEventHandler::GetSingleton();
		return inputHandler->GetKey();
	}

	void ACloserLook::SetKey(RE::StaticFunctionTag*, std::uint32_t a_key)
	{
		auto inputHandler = Events::InputEventHandler::GetSingleton();
		inputHandler->SetKey(a_key);
	}

	bool ACloserLook::Register(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->RegisterFunction("GetFOVDiff", "ACloserLook", GetFOVDiff);
		a_vm->RegisterFunction("SetFOVDiff", "ACloserLook", SetFOVDiff);
		a_vm->RegisterFunction("GetStep", "ACloserLook", GetStep);
		a_vm->RegisterFunction("SetStep", "ACloserLook", SetStep);
		a_vm->RegisterFunction("GetKey", "ACloserLook", GetKey);
		a_vm->RegisterFunction("SetKey", "ACloserLook", SetKey);
		_MESSAGE("Registered ACloserLook class");
		return true;
	}

	void Register()
	{
		auto papyrus = SKSE::GetPapyrusInterface();
		papyrus->Register(ACloserLook::Register);
		_MESSAGE("Registered papyrus functions");
	}
}
