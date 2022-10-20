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

class traj_out_msgRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.times = null;
    }
    else {
      if (initObj.hasOwnProperty('times')) {
        this.times = initObj.times
      }
      else {
        this.times = {secs: 0, nsecs: 0};
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type traj_out_msgRequest
    // Serialize message field [times]
    bufferOffset = _serializer.time(obj.times, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type traj_out_msgRequest
    let len;
    let data = new traj_out_msgRequest(null);
    // Deserialize message field [times]
    data.times = _deserializer.time(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'task_plan/traj_out_msgRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0a97ae2341ad1b2d6f0203e8c93f2964';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    time times
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new traj_out_msgRequest(null);
    if (msg.times !== undefined) {
      resolved.times = msg.times;
    }
    else {
      resolved.times = {secs: 0, nsecs: 0}
    }

    return resolved;
    }
};

class traj_out_msgResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x = null;
      this.dx = null;
      this.ddx = null;
      this.y = null;
      this.dy = null;
      this.ddy = null;
      this.z = null;
      this.dz = null;
      this.ddz = null;
      this.flag_begin = null;
    }
    else {
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('dx')) {
        this.dx = initObj.dx
      }
      else {
        this.dx = 0.0;
      }
      if (initObj.hasOwnProperty('ddx')) {
        this.ddx = initObj.ddx
      }
      else {
        this.ddx = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('dy')) {
        this.dy = initObj.dy
      }
      else {
        this.dy = 0.0;
      }
      if (initObj.hasOwnProperty('ddy')) {
        this.ddy = initObj.ddy
      }
      else {
        this.ddy = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('dz')) {
        this.dz = initObj.dz
      }
      else {
        this.dz = 0.0;
      }
      if (initObj.hasOwnProperty('ddz')) {
        this.ddz = initObj.ddz
      }
      else {
        this.ddz = 0.0;
      }
      if (initObj.hasOwnProperty('flag_begin')) {
        this.flag_begin = initObj.flag_begin
      }
      else {
        this.flag_begin = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type traj_out_msgResponse
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [dx]
    bufferOffset = _serializer.float64(obj.dx, buffer, bufferOffset);
    // Serialize message field [ddx]
    bufferOffset = _serializer.float64(obj.ddx, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [dy]
    bufferOffset = _serializer.float64(obj.dy, buffer, bufferOffset);
    // Serialize message field [ddy]
    bufferOffset = _serializer.float64(obj.ddy, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [dz]
    bufferOffset = _serializer.float64(obj.dz, buffer, bufferOffset);
    // Serialize message field [ddz]
    bufferOffset = _serializer.float64(obj.ddz, buffer, bufferOffset);
    // Serialize message field [flag_begin]
    bufferOffset = _serializer.bool(obj.flag_begin, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type traj_out_msgResponse
    let len;
    let data = new traj_out_msgResponse(null);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dx]
    data.dx = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ddx]
    data.ddx = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dy]
    data.dy = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ddy]
    data.ddy = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dz]
    data.dz = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ddz]
    data.ddz = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [flag_begin]
    data.flag_begin = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 73;
  }

  static datatype() {
    // Returns string type for a service object
    return 'task_plan/traj_out_msgResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f97b608cddafab5116084894b452b134';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 x
    float64 dx
    float64 ddx
    float64 y
    float64 dy
    float64 ddy
    float64 z
    float64 dz
    float64 ddz
    bool flag_begin
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new traj_out_msgResponse(null);
    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.dx !== undefined) {
      resolved.dx = msg.dx;
    }
    else {
      resolved.dx = 0.0
    }

    if (msg.ddx !== undefined) {
      resolved.ddx = msg.ddx;
    }
    else {
      resolved.ddx = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.dy !== undefined) {
      resolved.dy = msg.dy;
    }
    else {
      resolved.dy = 0.0
    }

    if (msg.ddy !== undefined) {
      resolved.ddy = msg.ddy;
    }
    else {
      resolved.ddy = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.dz !== undefined) {
      resolved.dz = msg.dz;
    }
    else {
      resolved.dz = 0.0
    }

    if (msg.ddz !== undefined) {
      resolved.ddz = msg.ddz;
    }
    else {
      resolved.ddz = 0.0
    }

    if (msg.flag_begin !== undefined) {
      resolved.flag_begin = msg.flag_begin;
    }
    else {
      resolved.flag_begin = false
    }

    return resolved;
    }
};

module.exports = {
  Request: traj_out_msgRequest,
  Response: traj_out_msgResponse,
  md5sum() { return 'd5e5f46daf7567dab08610da48ae237e'; },
  datatype() { return 'task_plan/traj_out_msg'; }
};
