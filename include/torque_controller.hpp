#ifndef TORQUE_CONTROLLER_H
#define TORQUE_CONTROLLER_H
#pragma once
#include <KDetailedException.h>
#include <BaseCyclicClientRpc.h> 
#include <BaseClientRpc.h> 
#include <ActuatorConfigClientRpc.h> 
#include <eigen3/Eigen/Core>
#include <friction_observer.hpp>
namespace k_api = Kinova::Api;

class torque_controller  
{
	private:

	public:
		bool cyclic_torque_control(k_api::Base::BaseClient* base, k_api::BaseCyclic::BaseCyclicClient* base_cyclic, k_api::ActuatorConfig::ActuatorConfigClient* actuator_config);
		int enforce_loop_frequency(const int dt);
};
#endif