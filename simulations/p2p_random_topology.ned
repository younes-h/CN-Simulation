//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package p2p_sim.simulations;

simple P2PRandomTopologyNode extends P2PNode {
    @class(P2PRandomTopologyNode);
}

network P2PNetRandomTopology {
    parameters:
        int count;
        double connectedness;
    submodules:
        node[count] : P2PRandomTopologyNode;
    connections allowunconnected:
        for i=0..count-1, for j=0..count-1 {
            node[i].gate++ <--> node[j].gate++ if i!=j && uniform(0,1) < connectedness;
        }
}