//
// Generated file, do not edit! Created by nedtool 5.4 from pow_msg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __POW_MSG_M_H
#define __POW_MSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>pow_msg.msg:16</tt> by nedtool.
 * <pre>
 * message POWMsg
 * {
 *     string data; // xml data
 *     string command; // name of command to execute upon reaching destination 
 *     int src; // source node index of the sending node
 * }
 * </pre>
 */
class POWMsg : public ::omnetpp::cMessage
{
  protected:
    ::omnetpp::opp_string data;
    ::omnetpp::opp_string command;
    int src;

  private:
    void copy(const POWMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const POWMsg&);

  public:
    POWMsg(const char *name=nullptr, short kind=0);
    POWMsg(const POWMsg& other);
    virtual ~POWMsg();
    POWMsg& operator=(const POWMsg& other);
    virtual POWMsg *dup() const override {return new POWMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getData() const;
    virtual void setData(const char * data);
    virtual const char * getCommand() const;
    virtual void setCommand(const char * command);
    virtual int getSrc() const;
    virtual void setSrc(int src);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const POWMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, POWMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __POW_MSG_M_H

