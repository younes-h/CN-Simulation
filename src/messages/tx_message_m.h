//
// Generated file, do not edit! Created by nedtool 5.4 from messages/tx_message.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __TX_MESSAGE_M_H
#define __TX_MESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
    #include "../blockchain/tx.h"
    #include "pow_message_m.h"
// }}

/**
 * Class generated from <tt>messages/tx_message.msg:24</tt> by nedtool.
 * <pre>
 * message TxMessage extends POWMessage
 * {
 *     Transaction tx;
 * }
 * </pre>
 */
class TxMessage : public ::POWMessage
{
  protected:
    Transaction tx;

  private:
    void copy(const TxMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TxMessage&);

  public:
    TxMessage(const char *name=nullptr, short kind=0);
    TxMessage(const TxMessage& other);
    virtual ~TxMessage();
    TxMessage& operator=(const TxMessage& other);
    virtual TxMessage *dup() const override {return new TxMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual Transaction& getTx();
    virtual const Transaction& getTx() const {return const_cast<TxMessage*>(this)->getTx();}
    virtual void setTx(const Transaction& tx);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TxMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TxMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __TX_MESSAGE_M_H

