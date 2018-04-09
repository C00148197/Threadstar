#include "NodeLayout.h"

NodeLayout::NodeLayout(std::vector<SDL_Point> &nodeData) {
	m_noOfNodes = nodeData.size() + 1;

	m_nodes = new Node*[m_noOfNodes];

	for (int i = 0; i < nodeData.size(); i++) {
		m_nodes[i] = new Node(nodeData.at(i), i);
		m_nodes[i]->setMarked(false);
	}

	addArcs();
}

void NodeLayout::addArcs() {
	/********************************************//**
	*  ...  add arcs between nodes
***********************************************/


//add this in loop maybe or something since they all need to know neighbours?


	m_nodes[0]->addArc(m_nodes[1]);
	m_nodes[1]->addArc(m_nodes[0]);


	m_nodes[1]->addArc(m_nodes[2]);
	m_nodes[2]->addArc(m_nodes[1]);

	m_nodes[2]->addArc(m_nodes[3]);
	m_nodes[3]->addArc(m_nodes[2]);




	m_nodes[3]->addArc(m_nodes[4]);
	m_nodes[4]->addArc(m_nodes[3]);


	m_nodes[4]->addArc(m_nodes[5]);
	m_nodes[5]->addArc(m_nodes[4]);

	//bonus
	m_nodes[1]->addArc(m_nodes[3]);
	m_nodes[3]->addArc(m_nodes[1]);
	//w

	m_nodes[2]->addArc(m_nodes[4]);
	m_nodes[4]->addArc(m_nodes[2]);

	m_nodes[4]->addArc(m_nodes[6]);
	m_nodes[6]->addArc(m_nodes[4]);

}

int NodeLayout::getNoOfNodes() {
	return m_noOfNodes;
}

Node** NodeLayout::getNodes() {
	return m_nodes;
}