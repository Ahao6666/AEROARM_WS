// Auto-generated. Do not edit!

// (in-package navigator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class response {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.finished_behavior = null;
      this.uav_id = null;
      this.behavior_received = null;
      this.behavior_finished = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('finished_behavior')) {
        this.finished_behavior = initObj.finished_behavior
      }
      else {
        this.finished_behavior = 0;
      }
      if (initObj.hasOwnProperty('uav_id')) {
        this.uav_id = initObj.uav_id
      }
      else {
        this.uav_id = 0;
      }
      if (initObj.hasOwnProperty('behavior_received')) {
        this.behavior_received = initObj.behavior_received
      }
      else {
        this.behavior_received = false;
      }
      if (initObj.hasOwnProperty('behavior_finished')) {
        this.behavior_finished = initObj.behavior_finished
      }
      else {
        this.behavior_finished = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type response
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [finished_behavior]
    bufferOffset = _serializer.int8(obj.finished_behavior, buffer, bufferOffset);
    // Serialize message field [uav_id]
    bufferOffset = _serializer.int8(obj.uav_id, buffer, bufferOffset);
    // Serialize message field [behavior_received]
    bufferOffset = _serializer.bool(obj.behavior_received, buffer, bufferOffset);
    // Serialize message field [behavior_finished]
    bufferOffset = _serializer.bool(obj.behavior_finished, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type response
    let len;
    let data = new response(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [finished_behavior]
    data.finished_behavior = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [uav_id]
    data.uav_id = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [behavior_received]
    data.behavior_received = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [behavior_finished]
    data.behavior_finished = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'navigator/response';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3a2625249be6a4aa28101b91b984ef1a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int8   finished_behavior
    int8   uav_id
    bool   behavior_received
    bool   behavior_finished
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new response(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.finished_behavior !== undefined) {
      resolved.finished_behavior = msg.finished_behavior;
    }
    else {
      resolved.finished_behavior = 0
    }

    if (msg.uav_id !== undefined) {
      resolved.uav_id = msg.uav_id;
    }
    else {
      resolved.uav_id = 0
    }

    if (msg.behavior_received !== undefined) {
      resolved.behavior_received = msg.behavior_received;
    }
    else {
      resolved.behavior_received = false
    }

    if (msg.behavior_finished !== undefined) {
      resolved.behavior_finished = msg.behavior_finished;
    }
    else {
      resolved.behavior_finished = false
    }

    return resolved;
    }
};

module.exports = response;
