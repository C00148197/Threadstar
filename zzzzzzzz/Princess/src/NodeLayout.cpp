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


void NodeLayout::setNodesPerLine(int incPerLine)
{
	nodesPerLines = incPerLine;
}

void NodeLayout::setSize(int incSize)
{
	size = incSize;
}

void NodeLayout::addArcs() {
	/********************************************//**
	*  ...  add arcs between nodes
***********************************************/


//add this in loop maybe or something since they all need to know neighbours?
	int col = 1;

	for (int i = 0; i < size; i++) {
		if (i == (nodesPerLines * col)) {
			col++;
		}

		if ((i + nodesPerLines) < size) {
			m_nodes[i]->addArc(m_nodes[i] + nodesPerLines);
			m_nodes[i+nodesPerLines]->addArc(m_nodes[i]);
		}

		if ((i + 1) < size) {
			if (i < (nodesPerLines * col) - 1) {
				m_nodes[i]->addArc(m_nodes[i] + 1);
				m_nodes[i+1]->addArc(m_nodes[i]);
			}
		}

		if (i + 1 + nodesPerLines < size) {
			if (i < (nodesPerLines * col) - 1) {
				m_nodes[i]->addArc(m_nodes[i] + 1 + nodesPerLines);
				m_nodes[i + 1 + nodesPerLines]->addArc(m_nodes[i]);
			}
		}

		if ((i + 1) - nodesPerLines >= 0) {
			m_nodes[i]->addArc(m_nodes[(i + 1) - nodesPerLines]);
			m_nodes[(i + 1) - nodesPerLines]->addArc(m_nodes[i]);
		}
	}

}

int NodeLayout::getNoOfNodes() {
	return m_noOfNodes;
}

Node** NodeLayout::getNodes() {
	return m_nodes;
}