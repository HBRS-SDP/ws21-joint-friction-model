#include<data_collector.hpp>
#include<yaml/Yaml.hpp>
#include<iostream>
#include <cmath>
using namespace std;
using namespace Yaml;

// function to recieve values from sensors
void Data_collector::get_dynamic_data(double jnt_ctrl_torque_vec,double jnt_position_vec,double jnt_velocity_vec,double jnt_torque_vec,double jnt_command_current_vec,double jnt_current_vec,double friction_torque_vec){

  this->sensor_values.push_back(jnt_ctrl_torque_vec);
  this->sensor_values.push_back(jnt_position_vec);
  this->sensor_values.push_back(jnt_velocity_vec);
  this->sensor_values.push_back(jnt_torque_vec);
  this->sensor_values.push_back(jnt_command_current_vec);
  this->sensor_values.push_back(jnt_current_vec);
  this->sensor_values.push_back(friction_torque_vec);
}
// Function to save data in csv file
void Data_collector:: save_dynamic_data(double velocity_value){
    Yaml::Node root;
    Yaml::Parse(root, "../configs/constants.yml");
    int parameter_count=root["PARAMETERS_COUNT"].As<int>();
    int rows=this->sensor_values.size();
    int counter=1;
    ofstream myfile;
    myfile.open("../data/velocity_"+std::to_string(velocity_value)+"readings.csv");
    for (int i = 0; i < rows; i++)
    {
        myfile << this->sensor_values[i]<< " ";
        if(counter==parameter_count){
            counter=1;
            myfile <<"\n";
            continue;
        }
        counter++;
    }     
    myfile.close();
    this->sensor_values.clear();
}

void Data_collector :: save_static_torques_values(double static_torque_value){

    this->static_friction_torque_values.push_back(static_torque_value);

}

void Data_collector :: save_static_torques_breakawy_point(double static_torque_breakaway_point){

    this->static_friction_torque_breakaway_point.push_back(static_torque_breakaway_point);

}

void Data_collector :: save_static_torques_rate(double static_torque_rate){

    this->static_friction_torque_rate.push_back(static_torque_rate);

}

// creating a file to save static torque values
void Data_collector :: create_static_torque_value_file(){
    int rows2 = this->static_friction_torque_breakaway_point.size();
    ofstream myfile;
    myfile.open("../data/static_data/static_torque_breakaway_point.csv");
    
    for (int i = 0; i < rows2; i++)
    {
        myfile << this->static_friction_torque_breakaway_point[i]<< " " << this->static_friction_torque_rate[i]<< endl;
    }     
    myfile.close();

}


