#pragma once

#define MAX_BEHAVIOR_NO 25

// behavior definitions
enum m_behavior {IDLE, WAYPOINT_FLIGHT,LAND, HOVER,TAKEOFF,FORWARD,BACKWARD,RIGHT,LEFT,UP,DOWN};


// Flag structure to receive from other modules or uavs
struct Flags_Received_stru
{
    bool action_finish_flag; // current action is finished
};
