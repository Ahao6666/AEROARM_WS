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

class interface {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.behavior = null;
      this.behaviormode = null;
      this.params = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('behavior')) {
        this.behavior = initObj.behavior
      }
      else {
        this.behavior = 0;
      }
      if (initObj.hasOwnProperty('behaviormode')) {
        this.behaviormode = initObj.behaviormode
      }
      else {
        this.behaviormode = 0;
      }
      if (initObj.hasOwnProperty('params')) {
        this.params = initObj.params
      }
      else {
        this.params = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type interface
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [behavior]
    bufferOffset = _serializer.uint8(obj.behavior, buffer, bufferOffset);
    // Serialize message field [behaviormode]
    bufferOffset = _serializer.uint8(obj.behaviormode, buffer, bufferOffset);
    // Serialize message field [params]
    bufferOffset = _serializer.float64(obj.params, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type interface
    let len;
    let data = new interface(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [behavior]
    data.behavior = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [behaviormode]
    data.behaviormode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [params]
    data.params = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'navigator/interface';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dae9a4e6d7acf972163a081d07c9c96d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #(1) waypoint flight: x,y,z,yaw in ENU frame
    
    Header header
    uint8  behavior
    uint8  behaviormode
    float64 params
    #geometry_msgs/PoseStamped[] uav_waypoint
    
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
    const resolved = new interface(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.behavior !== undefined) {
      resolved.behavior = msg.behavior;
    }
    else {
      resolved.behavior = 0
    }

    if (msg.behaviormode !== undefined) {
      resolved.behaviormode = msg.behaviormode;
    }
    else {
      resolved.behaviormode = 0
    }

    if (msg.params !== undefined) {
      resolved.params = msg.params;
    }
    else {
      resolved.params = 0.0
    }

    return resolved;
    }
};

module.exports = interface;
