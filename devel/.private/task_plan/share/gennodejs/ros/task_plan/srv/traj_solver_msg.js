// Auto-generated. Do not edit!

// (in-package task_plan.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class traj_solver_msgRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.s_scale = null;
      this.x_upperPosition = null;
      this.x_lowerPosition = null;
      this.x_upperVelocity = null;
      this.x_lowerVelocity = null;
      this.x_upperAccelera = null;
      this.x_lowerAccelera = null;
      this.x_0 = null;
      this.x_n = null;
      this.x_v0 = null;
      this.x_vn = null;
      this.y_upperPosition = null;
      this.y_lowerPosition = null;
      this.y_upperVelocity = null;
      this.y_lowerVelocity = null;
      this.y_upperAccelera = null;
      this.y_lowerAccelera = null;
      this.y_0 = null;
      this.y_n = null;
      this.y_v0 = null;
      this.y_vn = null;
      this.z_upperPosition = null;
      this.z_lowerPosition = null;
      this.z_upperVelocity = null;
      this.z_lowerVelocity = null;
      this.z_upperAccelera = null;
      this.z_lowerAccelera = null;
      this.z_0 = null;
      this.z_n = null;
      this.z_v0 = null;
      this.z_vn = null;
    }
    else {
      if (initObj.hasOwnProperty('s_scale')) {
        this.s_scale = initObj.s_scale
      }
      else {
        this.s_scale = 0.0;
      }
      if (initObj.hasOwnProperty('x_upperPosition')) {
        this.x_upperPosition = initObj.x_upperPosition
      }
      else {
        this.x_upperPosition = 0.0;
      }
      if (initObj.hasOwnProperty('x_lowerPosition')) {
        this.x_lowerPosition = initObj.x_lowerPosition
      }
      else {
        this.x_lowerPosition = 0.0;
      }
      if (initObj.hasOwnProperty('x_upperVelocity')) {
        this.x_upperVelocity = initObj.x_upperVelocity
      }
      else {
        this.x_upperVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('x_lowerVelocity')) {
        this.x_lowerVelocity = initObj.x_lowerVelocity
      }
      else {
        this.x_lowerVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('x_upperAccelera')) {
        this.x_upperAccelera = initObj.x_upperAccelera
      }
      else {
        this.x_upperAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('x_lowerAccelera')) {
        this.x_lowerAccelera = initObj.x_lowerAccelera
      }
      else {
        this.x_lowerAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('x_0')) {
        this.x_0 = initObj.x_0
      }
      else {
        this.x_0 = 0.0;
      }
      if (initObj.hasOwnProperty('x_n')) {
        this.x_n = initObj.x_n
      }
      else {
        this.x_n = 0.0;
      }
      if (initObj.hasOwnProperty('x_v0')) {
        this.x_v0 = initObj.x_v0
      }
      else {
        this.x_v0 = 0.0;
      }
      if (initObj.hasOwnProperty('x_vn')) {
        this.x_vn = initObj.x_vn
      }
      else {
        this.x_vn = 0.0;
      }
      if (initObj.hasOwnProperty('y_upperPosition')) {
        this.y_upperPosition = initObj.y_upperPosition
      }
      else {
        this.y_upperPosition = 0.0;
      }
      if (initObj.hasOwnProperty('y_lowerPosition')) {
        this.y_lowerPosition = initObj.y_lowerPosition
      }
      else {
        this.y_lowerPosition = 0.0;
      }
      if (initObj.hasOwnProperty('y_upperVelocity')) {
        this.y_upperVelocity = initObj.y_upperVelocity
      }
      else {
        this.y_upperVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('y_lowerVelocity')) {
        this.y_lowerVelocity = initObj.y_lowerVelocity
      }
      else {
        this.y_lowerVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('y_upperAccelera')) {
        this.y_upperAccelera = initObj.y_upperAccelera
      }
      else {
        this.y_upperAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('y_lowerAccelera')) {
        this.y_lowerAccelera = initObj.y_lowerAccelera
      }
      else {
        this.y_lowerAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('y_0')) {
        this.y_0 = initObj.y_0
      }
      else {
        this.y_0 = 0.0;
      }
      if (initObj.hasOwnProperty('y_n')) {
        this.y_n = initObj.y_n
      }
      else {
        this.y_n = 0.0;
      }
      if (initObj.hasOwnProperty('y_v0')) {
        this.y_v0 = initObj.y_v0
      }
      else {
        this.y_v0 = 0.0;
      }
      if (initObj.hasOwnProperty('y_vn')) {
        this.y_vn = initObj.y_vn
      }
      else {
        this.y_vn = 0.0;
      }
      if (initObj.hasOwnProperty('z_upperPosition')) {
        this.z_upperPosition = initObj.z_upperPosition
      }
      else {
        this.z_upperPosition = 0.0;
      }
      if (initObj.hasOwnProperty('z_lowerPosition')) {
        this.z_lowerPosition = initObj.z_lowerPosition
      }
      else {
        this.z_lowerPosition = 0.0;
      }
      if (initObj.hasOwnProperty('z_upperVelocity')) {
        this.z_upperVelocity = initObj.z_upperVelocity
      }
      else {
        this.z_upperVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('z_lowerVelocity')) {
        this.z_lowerVelocity = initObj.z_lowerVelocity
      }
      else {
        this.z_lowerVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('z_upperAccelera')) {
        this.z_upperAccelera = initObj.z_upperAccelera
      }
      else {
        this.z_upperAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('z_lowerAccelera')) {
        this.z_lowerAccelera = initObj.z_lowerAccelera
      }
      else {
        this.z_lowerAccelera = 0.0;
      }
      if (initObj.hasOwnProperty('z_0')) {
        this.z_0 = initObj.z_0
      }
      else {
        this.z_0 = 0.0;
      }
      if (initObj.hasOwnProperty('z_n')) {
        this.z_n = initObj.z_n
      }
      else {
        this.z_n = 0.0;
      }
      if (initObj.hasOwnProperty('z_v0')) {
        this.z_v0 = initObj.z_v0
      }
      else {
        this.z_v0 = 0.0;
      }
      if (initObj.hasOwnProperty('z_vn')) {
        this.z_vn = initObj.z_vn
      }
      else {
        this.z_vn = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type traj_solver_msgRequest
    // Serialize message field [s_scale]
    bufferOffset = _serializer.float64(obj.s_scale, buffer, bufferOffset);
    // Serialize message field [x_upperPosition]
    bufferOffset = _serializer.float64(obj.x_upperPosition, buffer, bufferOffset);
    // Serialize message field [x_lowerPosition]
    bufferOffset = _serializer.float64(obj.x_lowerPosition, buffer, bufferOffset);
    // Serialize message field [x_upperVelocity]
    bufferOffset = _serializer.float64(obj.x_upperVelocity, buffer, bufferOffset);
    // Serialize message field [x_lowerVelocity]
    bufferOffset = _serializer.float64(obj.x_lowerVelocity, buffer, bufferOffset);
    // Serialize message field [x_upperAccelera]
    bufferOffset = _serializer.float64(obj.x_upperAccelera, buffer, bufferOffset);
    // Serialize message field [x_lowerAccelera]
    bufferOffset = _serializer.float64(obj.x_lowerAccelera, buffer, bufferOffset);
    // Serialize message field [x_0]
    bufferOffset = _serializer.float64(obj.x_0, buffer, bufferOffset);
    // Serialize message field [x_n]
    bufferOffset = _serializer.float64(obj.x_n, buffer, bufferOffset);
    // Serialize message field [x_v0]
    bufferOffset = _serializer.float64(obj.x_v0, buffer, bufferOffset);
    // Serialize message field [x_vn]
    bufferOffset = _serializer.float64(obj.x_vn, buffer, bufferOffset);
    // Serialize message field [y_upperPosition]
    bufferOffset = _serializer.float64(obj.y_upperPosition, buffer, bufferOffset);
    // Serialize message field [y_lowerPosition]
    bufferOffset = _serializer.float64(obj.y_lowerPosition, buffer, bufferOffset);
    // Serialize message field [y_upperVelocity]
    bufferOffset = _serializer.float64(obj.y_upperVelocity, buffer, bufferOffset);
    // Serialize message field [y_lowerVelocity]
    bufferOffset = _serializer.float64(obj.y_lowerVelocity, buffer, bufferOffset);
    // Serialize message field [y_upperAccelera]
    bufferOffset = _serializer.float64(obj.y_upperAccelera, buffer, bufferOffset);
    // Serialize message field [y_lowerAccelera]
    bufferOffset = _serializer.float64(obj.y_lowerAccelera, buffer, bufferOffset);
    // Serialize message field [y_0]
    bufferOffset = _serializer.float64(obj.y_0, buffer, bufferOffset);
    // Serialize message field [y_n]
    bufferOffset = _serializer.float64(obj.y_n, buffer, bufferOffset);
    // Serialize message field [y_v0]
    bufferOffset = _serializer.float64(obj.y_v0, buffer, bufferOffset);
    // Serialize message field [y_vn]
    bufferOffset = _serializer.float64(obj.y_vn, buffer, bufferOffset);
    // Serialize message field [z_upperPosition]
    bufferOffset = _serializer.float64(obj.z_upperPosition, buffer, bufferOffset);
    // Serialize message field [z_lowerPosition]
    bufferOffset = _serializer.float64(obj.z_lowerPosition, buffer, bufferOffset);
    // Serialize message field [z_upperVelocity]
    bufferOffset = _serializer.float64(obj.z_upperVelocity, buffer, bufferOffset);
    // Serialize message field [z_lowerVelocity]
    bufferOffset = _serializer.float64(obj.z_lowerVelocity, buffer, bufferOffset);
    // Serialize message field [z_upperAccelera]
    bufferOffset = _serializer.float64(obj.z_upperAccelera, buffer, bufferOffset);
    // Serialize message field [z_lowerAccelera]
    bufferOffset = _serializer.float64(obj.z_lowerAccelera, buffer, bufferOffset);
    // Serialize message field [z_0]
    bufferOffset = _serializer.float64(obj.z_0, buffer, bufferOffset);
    // Serialize message field [z_n]
    bufferOffset = _serializer.float64(obj.z_n, buffer, bufferOffset);
    // Serialize message field [z_v0]
    bufferOffset = _serializer.float64(obj.z_v0, buffer, bufferOffset);
    // Serialize message field [z_vn]
    bufferOffset = _serializer.float64(obj.z_vn, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type traj_solver_msgRequest
    let len;
    let data = new traj_solver_msgRequest(null);
    // Deserialize message field [s_scale]
    data.s_scale = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_upperPosition]
    data.x_upperPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_lowerPosition]
    data.x_lowerPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_upperVelocity]
    data.x_upperVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_lowerVelocity]
    data.x_lowerVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_upperAccelera]
    data.x_upperAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_lowerAccelera]
    data.x_lowerAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_0]
    data.x_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_n]
    data.x_n = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_v0]
    data.x_v0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_vn]
    data.x_vn = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_upperPosition]
    data.y_upperPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_lowerPosition]
    data.y_lowerPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_upperVelocity]
    data.y_upperVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_lowerVelocity]
    data.y_lowerVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_upperAccelera]
    data.y_upperAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_lowerAccelera]
    data.y_lowerAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_0]
    data.y_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_n]
    data.y_n = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_v0]
    data.y_v0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_vn]
    data.y_vn = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_upperPosition]
    data.z_upperPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_lowerPosition]
    data.z_lowerPosition = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_upperVelocity]
    data.z_upperVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_lowerVelocity]
    data.z_lowerVelocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_upperAccelera]
    data.z_upperAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_lowerAccelera]
    data.z_lowerAccelera = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_0]
    data.z_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_n]
    data.z_n = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_v0]
    data.z_v0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z_vn]
    data.z_vn = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 248;
  }

  static datatype() {
    // Returns string type for a service object
    return 'task_plan/traj_solver_msgRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd2d10619491418a33c3811389a801280';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 s_scale  
    float64 x_upperPosition 
    float64 x_lowerPosition 
    float64 x_upperVelocity
    float64 x_lowerVelocity
    float64 x_upperAccelera
    float64 x_lowerAccelera
    float64 x_0
    float64 x_n
    float64 x_v0
    float64 x_vn
    float64 y_upperPosition 
    float64 y_lowerPosition 
    float64 y_upperVelocity
    float64 y_lowerVelocity
    float64 y_upperAccelera
    float64 y_lowerAccelera
    float64 y_0
    float64 y_n
    float64 y_v0
    float64 y_vn
    float64 z_upperPosition 
    float64 z_lowerPosition 
    float64 z_upperVelocity
    float64 z_lowerVelocity
    float64 z_upperAccelera
    float64 z_lowerAccelera
    float64 z_0
    float64 z_n
    float64 z_v0
    float64 z_vn
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new traj_solver_msgRequest(null);
    if (msg.s_scale !== undefined) {
      resolved.s_scale = msg.s_scale;
    }
    else {
      resolved.s_scale = 0.0
    }

    if (msg.x_upperPosition !== undefined) {
      resolved.x_upperPosition = msg.x_upperPosition;
    }
    else {
      resolved.x_upperPosition = 0.0
    }

    if (msg.x_lowerPosition !== undefined) {
      resolved.x_lowerPosition = msg.x_lowerPosition;
    }
    else {
      resolved.x_lowerPosition = 0.0
    }

    if (msg.x_upperVelocity !== undefined) {
      resolved.x_upperVelocity = msg.x_upperVelocity;
    }
    else {
      resolved.x_upperVelocity = 0.0
    }

    if (msg.x_lowerVelocity !== undefined) {
      resolved.x_lowerVelocity = msg.x_lowerVelocity;
    }
    else {
      resolved.x_lowerVelocity = 0.0
    }

    if (msg.x_upperAccelera !== undefined) {
      resolved.x_upperAccelera = msg.x_upperAccelera;
    }
    else {
      resolved.x_upperAccelera = 0.0
    }

    if (msg.x_lowerAccelera !== undefined) {
      resolved.x_lowerAccelera = msg.x_lowerAccelera;
    }
    else {
      resolved.x_lowerAccelera = 0.0
    }

    if (msg.x_0 !== undefined) {
      resolved.x_0 = msg.x_0;
    }
    else {
      resolved.x_0 = 0.0
    }

    if (msg.x_n !== undefined) {
      resolved.x_n = msg.x_n;
    }
    else {
      resolved.x_n = 0.0
    }

    if (msg.x_v0 !== undefined) {
      resolved.x_v0 = msg.x_v0;
    }
    else {
      resolved.x_v0 = 0.0
    }

    if (msg.x_vn !== undefined) {
      resolved.x_vn = msg.x_vn;
    }
    else {
      resolved.x_vn = 0.0
    }

    if (msg.y_upperPosition !== undefined) {
      resolved.y_upperPosition = msg.y_upperPosition;
    }
    else {
      resolved.y_upperPosition = 0.0
    }

    if (msg.y_lowerPosition !== undefined) {
      resolved.y_lowerPosition = msg.y_lowerPosition;
    }
    else {
      resolved.y_lowerPosition = 0.0
    }

    if (msg.y_upperVelocity !== undefined) {
      resolved.y_upperVelocity = msg.y_upperVelocity;
    }
    else {
      resolved.y_upperVelocity = 0.0
    }

    if (msg.y_lowerVelocity !== undefined) {
      resolved.y_lowerVelocity = msg.y_lowerVelocity;
    }
    else {
      resolved.y_lowerVelocity = 0.0
    }

    if (msg.y_upperAccelera !== undefined) {
      resolved.y_upperAccelera = msg.y_upperAccelera;
    }
    else {
      resolved.y_upperAccelera = 0.0
    }

    if (msg.y_lowerAccelera !== undefined) {
      resolved.y_lowerAccelera = msg.y_lowerAccelera;
    }
    else {
      resolved.y_lowerAccelera = 0.0
    }

    if (msg.y_0 !== undefined) {
      resolved.y_0 = msg.y_0;
    }
    else {
      resolved.y_0 = 0.0
    }

    if (msg.y_n !== undefined) {
      resolved.y_n = msg.y_n;
    }
    else {
      resolved.y_n = 0.0
    }

    if (msg.y_v0 !== undefined) {
      resolved.y_v0 = msg.y_v0;
    }
    else {
      resolved.y_v0 = 0.0
    }

    if (msg.y_vn !== undefined) {
      resolved.y_vn = msg.y_vn;
    }
    else {
      resolved.y_vn = 0.0
    }

    if (msg.z_upperPosition !== undefined) {
      resolved.z_upperPosition = msg.z_upperPosition;
    }
    else {
      resolved.z_upperPosition = 0.0
    }

    if (msg.z_lowerPosition !== undefined) {
      resolved.z_lowerPosition = msg.z_lowerPosition;
    }
    else {
      resolved.z_lowerPosition = 0.0
    }

    if (msg.z_upperVelocity !== undefined) {
      resolved.z_upperVelocity = msg.z_upperVelocity;
    }
    else {
      resolved.z_upperVelocity = 0.0
    }

    if (msg.z_lowerVelocity !== undefined) {
      resolved.z_lowerVelocity = msg.z_lowerVelocity;
    }
    else {
      resolved.z_lowerVelocity = 0.0
    }

    if (msg.z_upperAccelera !== undefined) {
      resolved.z_upperAccelera = msg.z_upperAccelera;
    }
    else {
      resolved.z_upperAccelera = 0.0
    }

    if (msg.z_lowerAccelera !== undefined) {
      resolved.z_lowerAccelera = msg.z_lowerAccelera;
    }
    else {
      resolved.z_lowerAccelera = 0.0
    }

    if (msg.z_0 !== undefined) {
      resolved.z_0 = msg.z_0;
    }
    else {
      resolved.z_0 = 0.0
    }

    if (msg.z_n !== undefined) {
      resolved.z_n = msg.z_n;
    }
    else {
      resolved.z_n = 0.0
    }

    if (msg.z_v0 !== undefined) {
      resolved.z_v0 = msg.z_v0;
    }
    else {
      resolved.z_v0 = 0.0
    }

    if (msg.z_vn !== undefined) {
      resolved.z_vn = msg.z_vn;
    }
    else {
      resolved.z_vn = 0.0
    }

    return resolved;
    }
};

class traj_solver_msgResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.resultstatus = null;
    }
    else {
      if (initObj.hasOwnProperty('resultstatus')) {
        this.resultstatus = initObj.resultstatus
      }
      else {
        this.resultstatus = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type traj_solver_msgResponse
    // Serialize message field [resultstatus]
    bufferOffset = _serializer.bool(obj.resultstatus, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type traj_solver_msgResponse
    let len;
    let data = new traj_solver_msgResponse(null);
    // Deserialize message field [resultstatus]
    data.resultstatus = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'task_plan/traj_solver_msgResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '02a1365fbb049f415398ed38aa76782f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool resultstatus
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new traj_solver_msgResponse(null);
    if (msg.resultstatus !== undefined) {
      resolved.resultstatus = msg.resultstatus;
    }
    else {
      resolved.resultstatus = false
    }

    return resolved;
    }
};

module.exports = {
  Request: traj_solver_msgRequest,
  Response: traj_solver_msgResponse,
  md5sum() { return '38d31568563b236264303ee6e91f80dd'; },
  datatype() { return 'task_plan/traj_solver_msg'; }
};
