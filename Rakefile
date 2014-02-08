# -*- ruby -*-
# myRobotLine Arduino sketch
#
# Copyright (c) 2012 Michael Margolis
# Copyright (c) 2013,2014 Dave Sieh
#
# See LICENSE.txt for details.
#
# Put the parent directory on the Ruby Load path
$: << File.dirname(File.dirname(__FILE__))

# Bring in the task support
require 'arduino-tasks/tasks'
include ArduinoTasks

BASE_DIR = '..'

env = ArduinoEnvironment.new BASE_DIR

LIBS = [
  library('AFMotor', 'Adafruit-Motor-Shield-library', 'robot_kit'),
  library('LEDBlinker'),
  library('RobotMotor'),
  library('SoftServo')
]

create_all_library_tasks env, LIBS, :default
#LIB_DIR = 'lib'
#BASE_DIR = '..'

#ADA_LIB = 'Adafruit-Motor-Shield-library'
#AFMOTOR_LIB = File.join(LIB_DIR, "AFMotor")

#directory AFMOTOR_LIB do
  #cp_r File.join(BASE_DIR, ADA_LIB), LIB_DIR
  #mv File.join(LIB_DIR, ADA_LIB), AFMOTOR_LIB
#end

#LIBS = %w{ LEDBlinker RobotMotor SoftServo }

#LIBS.each do | lib |
  #directory File.join(LIB_DIR, lib) do
    #cp_r File.join(BASE_DIR, lib, LIB_DIR, lib), LIB_DIR
  #end

  #task :default => File.join(LIB_DIR, lib)
#end

#task :default => AFMOTOR_LIB

