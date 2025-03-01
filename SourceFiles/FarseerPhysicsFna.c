#include <mono/metadata/appdomain.h>
#include <mono/mini/jit.h>

extern void** mono_aot_module_FarseerPhysicsFna_info;

void VMLFarseerPhysicsFnaRegister()
{
    mono_aot_register_module(mono_aot_module_FarseerPhysicsFna_info);
}