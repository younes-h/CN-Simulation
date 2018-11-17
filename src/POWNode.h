/*
 * POWNode.h
 *
 *  Created on: Nov 14, 2018
 *      Author: jburke
 */

#ifndef POWNODE_H_
#define POWNODE_H_

#include <omnetpp.h>
#include "P2PNode.h"
#include "pow_msg_m.h"

using namespace omnetpp;

/*! Node in a proof of work based blockchain network (i.e., Bitcoin, Litecoin, etc).
 *
 */
class POWNode: public P2PNode {
public:
    POWNode();
    virtual ~POWNode();
protected:
    /*! Initialize the node.  Occurs during the set up stage of the simulation, before any messages are sent.
     * Runs the following steps:
     * 1.  Establish connections with nodes in known node list (if no known nodes, just connect to a list of default nodes).
     * 2.  Broadcast our known nodes list (excluding default nodes)
     */
    virtual void initialize() override;

    /*! Process an incoming message.
     * \param msg Message to handle.  Will be cast to a POWMsg.
     */
    virtual void handleMessage(cMessage *msg) override;

    /*! Check if the node is online (would be handled by TCP timeouts in real network).  Connections will not be established with an offline node.
     * \returns True if the node is online and can be connected to, false otherwise.
     */
    bool isOnline() const;
private:
    /*! Create connections to currently known list of networks (step 1 of initialization).  Each connection will create a new gate in the source and destination nodes if needed.
     * In the future, the max number of connections may be a parameter in the network simulation (as the actual Bitcoin client has such a parameter).
     */
    void initConnections();

    /*! Create a new message that will ask a node to send over its list of known nodes.
     * This method does *not* handle actually sending the message!
     * \param dest *Node* index to send the message to.
     * \returns Message containing our list of currently known nodes and what node index we are.
     */
    POWMsg *generateGetKnownNodesMessage(int dest);
};

Define_Module(POWNode)

#endif /* POWNODE_H_ */
