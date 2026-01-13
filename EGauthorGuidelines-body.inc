% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v2.04, Dec 14, 2023

\usepackage{tikz}
\usepackage{amssymb}
\usepackage{graphicx}
\usepackage{booktabs}
\usepackage{hyperref}

\title[From Hairballs to Hypotheses]%
      {From Hairballs to Hypotheses: A Survey of AI-Assisted Visual Analytics in the Life Sciences}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
% for final version: please provide your *own* ORCID in the brackets following \orcid; see https://orcid.org/ for more details.
\author[Chukhman et al.]
{\parbox{\textwidth}{\centering
Morris Chukhman$^{1,2}$,
Amira Kefi$^{1}$,
Nicole M. Chukhman$^{3}$,
Silvio Rizzi$^{1,4}$,
Vinayakumar Chalil Karintha$^{5}$\,
and Angus Forbes$^{6}$\\[1ex]
{\small
$^{1}$University of Illinois at Chicago, Chicago, IL, USA\\
$^{2}$St. Luke's University Health Network, Stroudsburg, PA, USA \\
$^{3}$University of Wisconsin - Madison, Madison, WI, USA \\
$^{4}$Argonne National Laboratory, Lemont, IL, USA \\
$^{5}$UST, Thiruvananthapuram, Kerala, India \\
$^{6}$NVIDIA, Santa Clara, CA, USA \\
}
}
}
% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{36}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page


%-------------------------------------------------------------------------
\begin{document}

% uncomment for using teaser
% \teaser{
%  \includegraphics[width=0.9\linewidth]{eg_new}
%  \centering
%   \caption{New EG Logo}
% \label{fig:teaser}
%}

\maketitle
%-------------------------------------------------------------------------
\begin{abstract}
Visual analytics in the life sciences increasingly confronts “hairballs”: dense, heterogeneous, and multiscale data whose visual clutter and interaction overhead prevent analysts from forming, testing, and communicating hypotheses. In this State-of-the-Art Report, we synthesize research at the intersection of visualization modality and AI-assisted interaction for life science analytics. We organize the literature using a two-dimensional conceptual model that characterizes systems along two orthogonal axes: the visualization environment, ranging from conventional 2D desktop interfaces to large collaborative displays, immersive virtual and augmented reality, and hybrid cross-device ecosystems; and the mode of AI assistance, including algorithmic, adaptive, conversational, and immersive interaction support. To ground this synthesis in analytic practice, we consolidate prior task taxonomies into five task categories that capture common intents in life science analysis: navigation and multiscale orientation, comparison and differentiation, selection and precision interaction, sensemaking and hypothesis development, and coordination and collaborative reasoning. Using this framework, we summarize representative systems and mechanisms, discuss recurring evaluation practices and limitations, and highlight persistent design pressures related to scalability, representational fidelity, and auditability across hypothesis-driven workflows.

% ---------------------------------------------------------------
\section*{Keywords}
Biological Visualization, Network Visualization, Artificial Intelligence, Large Language Models, Immersive Analytics, Human–AI Collaboration, Design Studies, Cognitive Principles.

% ---------------------------------------------------------------
%-------------------------------------------------------------------------
%  ACM CCS 2012
%  (see https://www.acm.org/publications/class-2012)
%  The tool at https://dl.acm.org/ccs can be used to generate CCS codes.
%-------------------------------------------------------------------------

\begin{CCSXML}
<ccs2012>
  <concept>
    <concept_id>10003120.10003121.10011748</concept_id>
    <concept_desc>Human-centered computing~Visualization</concept_desc>
    <concept_significance>500</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003125.10010597</concept_id>
    <concept_desc>Human-centered computing~Visual analytics</concept_desc>
    <concept_significance>500</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003129</concept_id>
    <concept_desc>Human-centered computing~Interactive systems and tools</concept_desc>
    <concept_significance>300</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003124</concept_id>
    <concept_desc>Human-centered computing~Human computer interaction (HCI)</concept_desc>
    <concept_significance>200</concept_significance>
  </concept>
</ccs2012>
\end{CCSXML}

\ccsdesc[500]{Human-centered computing~Visualization}
\ccsdesc[500]{Human-centered computing~Visual analytics}
\ccsdesc[300]{Human-centered computing~Interactive systems and tools}
\ccsdesc[200]{Human-centered computing~Human computer interaction (HCI)}

\printccsdesc   
\end{abstract}  

%-------------------------------------------------------------------------
\section{Introduction}
% \textit{Introduce the context of life-science data (complex, high-dimensional “hairballs”), the challenges for visualization, and the rise of AI assistance. Define the goal and scope of the STAR. Provide an overview of the two-dimensional conceptual model (AI assistance modes crossed with visualization modalities) and the structure of the report.}
% \textit{(Remove this drafting note before submission.)}

Visual analytics in the life sciences has grown quickly over the last two decades because biological data are now larger, more heterogeneous, and more dynamic. Many workflows combine multiple data types in one analysis: \emph{-omics} profiles, spatially resolved measurements in tissue (spatial profiling / spatial transcriptomics), and high-resolution imaging that supports tasks like connectome reconstruction and circuit analysis \cite{Crosetto2015SpatialTranscriptomics,Moffitt2022SpatialProfiling,Beyer2022ConnectomicsSTAR}. These data often include dense relationships between genes, cells, regions, or neurons, that quickly become hard to read and hard to explore. This is the ``hairball'' problem in a broad sense: the display becomes cluttered and interaction breaks down just when analysts need overview, selection, and comparison. Systems therefore increasingly move beyond static depictions toward interactive environments that help users form and test hypotheses.

At the same time, the visualization toolkit itself has expanded. Desktop 2D tools remain the default, but many life-science workflows now also use large high-resolution displays and immersive platforms such as VR/AR and CAVE-like rooms. In parallel, visual analytics systems increasingly incorporate AI assistance, from algorithmic methods (e.g., clustering and dimensionality reduction) to adaptive interfaces and conversational interaction, to reduce manual burden and to support iterative reasoning. Immersive analytics occupies a particularly nuanced position in this space, since three-dimensional environments can both support spatial understanding and complicate reasoning when data are large and highly relational.



This State-of-the-Art Report (STAR) introduces a two-dimensional conceptual model that crosses \emph{AI Assistance Modes} with \emph{Visualization Modalities}. We distinguish four modes of AI assistance: \emph{algorithmic}, \emph{adaptive}, \emph{conversational}, and \emph{immersive} (i.e., assistance that leverages spatial/embodied interaction rather than simply using an immersive display); and five visualization modalities: \emph{2D desktop}, \emph{large displays}, \emph{virtual reality (VR)}, \emph{augmented reality (AR)}, and \emph{CAVE} environments. Using this matrix as an organizing framework, the STAR surveys how different combinations support life-science visual analytics, identifies recurring task and interaction taxonomies, and reviews evaluation methods, intelligent assistance mechanisms, and open research challenges \cite{Ehlers2025,Joos2025VisNetIA}.

Our goal is to provide a roadmap similar to Filipov et al.'s meta-survey of network visualization \cite{Filipov2023Roadmap}, but focused specifically on the intersection of AI assistance and visualization modality. The remainder of this STAR first establishes shared task foundations and a unified taxonomy for life-science visual analytics, then surveys the AI--modality matrix across desktop, large-display, and immersive settings, and finally synthesizes evaluation practices and open challenges that arise when moving from hairball depiction toward hypothesis-driven analysis.

\subsection{Scope and Definitions}
\label{sec:scope-defs}

Our work centers on life-science visual analytics problems where data items are connected by many relationships that can quickly become hard to see or explore. Particular attention is given to graphs and networks that appear across biology, such as protein–protein interaction networks, signaling pathways, and brain connectomes. We also consider cases where networks are not provided directly but are instead constructed from other data. For example, spatial-omics, tissue imaging, and neuronal tracing often yield neighborhood links or connectivity models that must be studied together with spatial and anatomical context. These different relationship types are described in more detail in Section \ref{sec:data-relationship-types}. 

Within this scope, we define AI assistance modes as follows:
\begin{itemize}
    \item \textbf{Algorithmic assistance} refers to automated computational analysis integrated into the visualization pipeline, such as graph mining, clustering, dimensionality reduction, or machine learning--based preprocessing.

    \item \textbf{Adaptive assistance} denotes systems that dynamically tailor visualizations or interactions based on user behavior, task context, or data characteristics.

    \item \textbf{Conversational assistance} encompasses natural language or dialogue-based interfaces that allow users to steer visual analysis through queries, explanations, or recommendations.

    \item \textbf{Immersive assistance} goes beyond merely displaying data in immersive environments and instead leverages immersion itself, through spatialization, embodiment, or multisensory cues, as an active mechanism for insight.
\end{itemize}

Visualization modalities are defined following established immersive analytics literature \cite{Fonnet2019ImmersiveAnalytics,Milgram1994MR} and include traditional 2D desktop setups; large displays such as powerwalls and tiled displays that afford high resolution and physical navigation; VR environments offering full immersion via head-mounted displays; AR systems that overlay visual information onto the physical world; and CAVE-like multi-screen immersive rooms supporting co-located collaboration. Each modality introduces distinct affordances and constraints. For example, VR and AR can enhance spatial understanding for certain analytical tasks \cite{Sedlmair2014GoodBadUgly,Ware2008Graphs3D}, while large displays support collaborative analysis by making many data items visible simultaneously.

Table \ref{table:taxonomy-matrix} summarizes our 4×5 matrix of AI assistance modes and visualization modalities, with representative research questions for each cell (e.g., How can conversational agents assist network exploration in VR? or How do adaptive techniques differ between 2D and AR for graph visualization?). This matrix serves as the structural backbone of the STAR. Our survey reveals that some combinations, such as algorithmic assistance in 2D desktop environments, are well studied, whereas others, such as conversational support in CAVE systems or adaptive AR analytics, remain sparsely explored. We highlight these imbalances throughout the report as indicators of open research gaps.

We do not attempt to survey the full breadth of bioimage analysis or computational biology. Instead, we prioritize systems and studies where interactive visualization is used to support analytical tasks over dense relationships, derived structures, or multiscale biological context. The scope of this review is more precisely defined in Section \ref{sec:scope-exclusions}.

% Conceptual Model: AI Assistance × Visualization Modality

\begin{table}[t]
\centering
\small
\resizebox{\columnwidth}{!}{
\begin{tabular}{l|c|c|c|c}
\textbf{Modality} & \textbf{Algorithmic} & \textbf{Adaptive} & \textbf{Conversational} & \textbf{Immersive} \\
\hline
Desktop (2D) & \checkmark & \checkmark & \checkmark & \(\sim\) \\
Large Display & \(\sim\) & \(\sim\) & \(\sim\) & \(\sim\) \\
VR & \checkmark & \(\sim\) & \(\sim\) & \checkmark \\
AR & \checkmark & \(\sim\) & — & \checkmark \\
CAVE/Hybrid & \(\sim\) & — & — & \(\sim\) \\
\end{tabular}
}
\caption{Visualization modalities can host any AI assistance mode; immersive-AI refers to AI techniques that operate specifically within immersive environments.
\checkmark = Supported (over 10 papers); \(\sim\) = Emerging (1-10 papers); 
— = Unsupported (no papers)}
\label{table:taxonomy-matrix}
\end{table}


\subsection{Methodology}

To collect the relevant literature, we conducted systematic searches across visualization, Human-Computer Interaction (HCI), and AI venues, informed by prior surveys and bibliographies \cite{Ehlers2025,Joos2025VisNetIA,Fonnet2019ImmersiveAnalytics}. In particular, we leveraged Joos et al.’s immersive network analysis survey (138 papers), Ehlers et al.’s survey of biological network visualization (83 papers), and Fonnet and Prié’s immersive analytics survey (177 works). We complemented these sources with targeted searches for combinations such as adaptive graph visualization, user modeling, and conversational visual analytics with large language models. We also reviewed recent STAR reports to ensure comprehensive coverage.

Publications were included if they addressed both visualization and AI or intelligent interaction aspects, and if they fell within the defined modality scope. Each major section of the STAR maps the surveyed literature onto our conceptual model and concludes with a synthesis of key trends, limitations, and opportunities for future work. Detailed publication research procedures are discussed in Appendix \ref{app:methodology}.

\begin{figure}[ht]
    \centering
    \includegraphics[width=0.5\textwidth]{grouped_barchart3.png}
    \caption{Distribution of relevant papers across AI Assistance Modes and Visualization Modalities. The chart highlights the dominance of Desktop interfaces for Algorithmic and Adaptive tasks, while Immersive-AI is heavily concentrated in VR environments.}
    \label{fig:paper_distribution}
\end{figure}

\section{Background and Scope}
% \textit{Establish foundational definitions and the survey’s scope.}

% \section{Background and Taxonomies}
\label{sec:background-taxonomies}

% Before examining specific combinations of AI assistance modes and visualization modalities, we first summarize the foundational task, interaction, and system taxonomies that underpin much of the literature surveyed in this report. These frameworks provide a common vocabulary for comparing systems across domains, modalities, and levels of intelligence, and they inform how we interpret the role of AI assistance throughout the visual analytics pipeline.
This section establishes the conceptual scope and definitions used throughout this State-of-the-Art Report. We define the types of data and relationships addressed, introduce the two dimensions of our survey matrix: visualization modalities and AI assistance modes, and clarify the boundaries of the literature considered. These definitions provide the context necessary for interpreting the task, interaction, and evaluation frameworks discussed in subsequent sections.

\subsection{Data and Relationship Types in Life-Science Visual Analytics}
%\textit{ Describe the types of biological data (networks, trajectories, spatial data, etc.) and relationships addressed by visual analytics in life sciences.}

% \subsection{Data and Relationship Types in Life-Science Visual Analytics}
\label{sec:data-relationship-types}

Life-science visual analytics encompasses a wide range of data types and relational structures. A central theme across many domains is the analysis of relationships, whether explicitly encoded as graphs or implicitly derived from spatial, temporal, or multivariate data. Common examples of explicit relational data include biological networks such as protein--protein interaction networks, gene regulatory networks, metabolic pathways, and connectomes, which may represent physical interactions, functional associations, or inferred statistical dependencies.

In addition to explicit networks, life-science analytics frequently involves spatially and temporally grounded data that give rise to relational structure. Examples include neuronal morphologies reconstructed from imaging, spatial organization of cells in tissue, trajectories of cells or molecules over time, and longitudinal clinical measurements. In these settings, relationships are often derived implicitly through spatial adjacency, neighborhood graphs, lineage trees, or similarity measures, rather than provided explicitly as node--link structures.

These heterogeneous data types commonly coexist within a single analytical workflow. For example, molecular interaction networks may be analyzed alongside genomic signals, experimental metadata, spatial context, or image-derived structures. As a result, visual analytics systems in the life sciences must support reasoning across multiple relationship types, scales, and representations. Throughout this report, we use biological networks as a recurring and illustrative example of relational complexity, while recognizing that many of the principles discussed generalize to other forms of relational and multivariate data encountered in contemporary life-science analytics.



\subsection{Visualization Modalities (Matrix Dimension~1)}
%\textit{ Define the visualization environments considered (2D desktop, large displays, VR, AR, CAVE) and their differing affordances.}
 % \subsection{Visualization Modalities}
\label{sec:visualization-modalities-intro}

The first dimension of our conceptual model distinguishes visualization modalities [\ref{sec:visualization-modalities}], defined by the physical and technological environment in which visual analytics takes place. We consider five primary modalities commonly addressed in the visualization literature: traditional 2D desktop environments [\ref{sec:desktop-2d}], large displays (including powerwalls and tiled displays) [\ref{sec:large-displays}], virtual reality (VR) environments, augmented reality (AR) systems, and CAVE-like multi-screen immersive rooms[\ref{sec:immersive-environments}].

Each modality affords different perceptual, cognitive, and collaborative capabilities. Desktop environments emphasize precision, familiarity, and integration with computational workflows. Large displays enable shared viewing, physical navigation, and collaborative sensemaking. VR environments support stereoscopic depth, embodied navigation, and spatial immersion. AR systems overlay analytical content onto the physical world, enabling contextualized analysis, while CAVE environments combine large-scale immersion with co-located collaboration. We adopt standard definitions of these modalities from immersive analytics and visualization research, and analyze how their differing affordances shape analytic workflows in later sections.

\subsection{AI Assistance Modes (Matrix Dimension~2)}
%\textit{ Define the modes of AI assistance (algorithmic, adaptive, conversational, immersive-AI) that augment visual analytics workflows.}
 % \subsection{AI Assistance Modes}
\label{sec:ai-assistance-modes}

The second dimension of our survey matrix characterizes how AI assistance augments visual analytics systems. As defined in Section \ref{sec:scope-defs}, we distinguish four broad modes of assistance: algorithmic, adaptive, conversational, and immersive. Algorithmic assistance is precomputed and primarily operates on data and structure, providing computational leverage through techniques such as clustering, dimensionality reduction, graph mining, or learned models. Adaptive assistance focuses on the user and task context, adjusting visual encodings or interactions in response to observed behavior or inferred intent, in real-time. Conversational assistance shifts interaction toward natural language, enabling users to express analytical goals through queries, explanations, or dialogue. Immersive assistance differs from the other modes by treating spatialization, embodiment, and multisensory interaction not merely as interface features, but as integral components of the analytical process itself. These modes are not mutually exclusive, and many systems combine multiple forms of assistance. Throughout this STAR, we use this classification to analyze how different AI capabilities interact with visualization modalities, and how these combinations shape task support, usability, and analytic outcomes.

\subsection{Task Foundations for Life-Science Visual Analytics}
%\textit{ Introduce prior task taxonomies from network visualization, immersive analytics, etc., that underpin the unified task framework in this STAR.}
 % \subsection{Task Foundations for Life-Science Visual Analytics}
\label{sec:task-foundations-into}

Visual analytics research is grounded in a rich body of task and interaction taxonomies developed for graph visualization, immersive analytics, and exploratory analysis. These frameworks provide a basis for describing analytical intent, interaction strategies, and evaluation methodologies across diverse systems. Rather than introducing new task definitions, this STAR builds upon established taxonomies to compare how different AI assistance modes and visualization modalities support core analytical activities. A detailed discussion of these task foundations is provided in Section~\ref{sec:task-foundations}.

\subsection{Scope and Exclusions}
% \textit{ Clearly state what is included (biological visual analytics with AI assistance) and excluded (purely manual vis, non-analytic visuals, non-bio contexts) from this survey.}
% \subsection{Scope and Exclusions}
\label{sec:scope-exclusions}

This report focuses on visual analytics systems that combine biological data analysis with some form of AI assistance across the visualization modalities defined above. We include systems that integrate computational analysis, adaptive interaction, conversational interfaces, or immersive reasoning into visual analytics workflows. The primary application focus is on life-science domains, particularly those involving complex relational or spatial data.

We exclude purely manual visualization systems that do not incorporate AI-assisted components, as well as visualization approaches intended solely for presentation or artistic purposes rather than analysis. While some concepts discussed may generalize beyond biology, systems developed exclusively for non-biological domains are considered only insofar as they inform transferable design principles.

\section{Unified Task Taxonomy}
% \textit{ Present the new integrated task taxonomy for AI-assisted visual analytics in life sciences.}
% \section{Task and Interaction Foundations}
\label{sec:task-foundations}

This section reviews established task and interaction frameworks that underpin the systems surveyed in this report. These foundations provide a shared vocabulary for analyzing how AI assistance and visualization modality influence analytical workflows, user interaction, and evaluation.


\subsection{Rationale: Why Existing Visualization Taxonomies Are No Longer Enough}
% \textit{ Explain three reasons motivating a new taxonomy (e.g., active AI agents, multiscale bio data, immersive modality challenges).}

% \subsection{Rationale: Why Existing Visualization Taxonomies Are No Longer Enough}
\label{sec:taxonomy-rationale}

Task taxonomies have played a central role in structuring visualization research, guiding both system design and evaluation. In graph visualization, influential taxonomies such as those proposed by Lee et al.\ categorize tasks according to graph objects (nodes, edges, paths, groups) and analytical goals, including topology-based, attribute-based, and overview tasks~\cite{Lee2006TaskTaxonomy}. More general visual analytics frameworks, such as Brehmer and Munzner’s multi-level typology, organize tasks along the dimensions of \emph{why} (user intent), \emph{how} (interaction), and \emph{what} (data target), providing a flexible lens for analyzing interaction across visualization systems~\cite{Brehmer2013WhyHowWhat,Munzner2014VisualizationAnalysis}. These frameworks have proven highly effective for characterizing analysis in traditional, largely manual visualization settings.

However, recent developments in both data characteristics and analytical systems challenge the sufficiency of existing task taxonomies when applied to contemporary life-science visual analytics. First, biological data has grown not only in scale but also in heterogeneity and dynamism. Ehlers et al.\ observe that biological network visualization increasingly involves multiscale data, heterogeneous relationships, and evolving experimental contexts, placing demands on analytical workflows that extend beyond the static task formulations assumed by many earlier taxonomies~\cite{Ehlers2025}. While domain-specific task adaptations exist, these typically extend general graph tasks rather than reconceptualizing how tasks unfold in the presence of automated analysis or intelligent guidance.

Second, immersive analytics introduces new task dimensions that are not fully captured by traditional taxonomies. Fonnet and Prié highlight that immersive systems reshape analytical activity through spatialization, embodiment, and collaboration, affecting not only how tasks are performed but also which tasks become feasible or salient~\cite{Fonnet2019ImmersiveAnalytics}. Tasks related to spatial understanding, navigation, and embodied comparison emerge alongside classical graph analysis tasks, blurring the boundary between interaction mechanics and analytical intent. As immersive environments increasingly support collaborative and multisensory analysis, task frameworks that abstract away modality-specific affordances become insufficient for meaningful comparison.

Third, and most critically, the increasing presence of AI assistance alters the locus of analytical agency. Existing taxonomies largely assume that users explicitly initiate and control analytical operations, with computational methods serving as passive tools. In contrast, AI-assisted systems may proactively suggest views, detect patterns, adapt representations, or engage in dialogue with the user. Filipov et al.\ identify the integration of machine learning for pattern mining and recommendation as a key open challenge in network visualization, noting that such capabilities fundamentally change how analysts interact with and reason about data~\cite{Filipov2023Roadmap}. Under these conditions, tasks can no longer be described solely in terms of user-driven actions; they must also account for system-initiated analysis, adaptive behavior, and mixed-initiative workflows.

Together, these developments motivate the need for a unified task taxonomy that explicitly accounts for three interacting dimensions: the analytical task itself, the visualization modality in which it is performed, and the mode of AI assistance that mediates the interaction. Rather than replacing existing taxonomies, such a framework builds upon them to enable systematic comparison across AI-assisted visual analytics systems operating in diverse modalities. In the following sections, we introduce this unified taxonomy and use it to structure our survey of AI-assisted visual analytics in the life sciences.

\subsection{The Unified Task Taxonomy}
\label{sec:unified-task-taxonomy}

To address the limitations identified in Section~\ref{sec:taxonomy-rationale}, we propose a unified task taxonomy for AI-assisted visual analytics in the life sciences. The taxonomy provides a structured lens for comparing how analytical tasks are supported and transformed across visualization modalities and AI assistance.

We organize the design space along three axes: (1) \emph{what} analytical task is being performed, (2) \emph{where} the task is enacted in terms of visualization modality, and (3) \emph{how} the task is mediated by AI assistance. These axes reflect increasing task complexity in biological data, modality-dependent affordances (e.g., large displays and immersive environments), and AI’s growing role as an active analytical agent.

The first dimension, \emph{analytical task}, builds on established task taxonomies in graph visualization and visual analytics. Rather than enumerating fine-grained operations, we define generalized task categories that capture recurring intent in biological workflows (e.g., exploration, comparison, abstraction, and hypothesis refinement). The categories are abstract enough to cover both manual and AI-mediated variants while remaining grounded in prior frameworks.

The second dimension, \emph{visualization modality}, encodes the environment in which a task is performed (2D desktop systems, large displays, immersive VR, AR, and CAVE-like setups). Treating modality as a first-class axis accounts for how perceptual, spatial, and collaborative affordances shape task execution and enables direct comparisons of the same task across environments.

The third dimension, \emph{AI assistance mode}, characterizes how computational intelligence intervenes in analysis. We distinguish algorithmic, adaptive, conversational, and immersive assistance (Section~\ref{sec:ai-assistance-modes}) and use this axis to capture the degree and form of system initiative: tasks may be user-driven, system-suggested, adaptively guided, or jointly negotiated through dialogue, reflecting mixed-initiative workflows.

Together, these dimensions enable systematic categorization of the STAR literature: each system can be positioned by the tasks it supports, the modality in which those tasks occur, and the assistance mode it employs. This structure helps surface patterns and gaps (e.g., task categories that are well supported algorithmically in 2D tools but underexplored in immersive or conversational settings).

In Section~\ref{sec:task-categories}, we instantiate the framework with generalized task categories that provide the organizational backbone for the remainder of the paper.

\subsection{Task Categories in the Unified Taxonomy}
% \textit{List and define the generalized task categories that span life-science visual analytics.}
\label{sec:task-categories}

This subsection defines the generalized task categories that constitute the unified taxonomy for AI-assisted visual analytics in the life sciences. The categories capture recurring analytical intent across biological workflows while remaining abstract enough to span visualization modalities and modes of AI assistance.

Prior task taxonomies in graph visualization and visual analytics characterize intent from object-centric (Lee et al.~\cite{Lee2006TaskTaxonomy}), intent-centric (Munzner~\cite{Munzner2014VisualizationAnalysis}), or technology-centric (Filipov et al.~\cite{Filipov2023Roadmap}) perspectives. We synthesize recurring intents across these frameworks into modality-aware and AI-aware task classes suited to mixed-initiative visual analytics.

The unified taxonomy comprises five task categories:
\begin{itemize}
    \item \emph{Navigation and Multiscale Orientation}
    \item \emph{Comparison and Differentiation}
    \item \emph{Selection, Filtering, and Precision Interaction}
    \item \emph{Sensemaking and Hypothesis Development}
    \item \emph{Coordination and Collaborative Reasoning}
\end{itemize}
Together, these categories span activities from individual exploration and precise interaction to collective reasoning and hypothesis refinement.

Each category may be instantiated differently depending on visualization modality and AI assistance mode. Rather than enumerating representative systems in a standalone section, we integrate examples throughout the task-driven discussion, using modality and assistance mode to contextualize design trade-offs and open challenges across mixed-initiative workflows.

\subsubsection{Navigation and Multiscale Orientation}
\label{sec:automated-view-switching}
% \textit{E.g., zooming across scales, traversing networks or anatomy, viewpoint management, note why AI (e.g., guided navigation) is essential for deep 3D or multiscale navigation.}

Navigation and multiscale orientation encompass tasks in which analysts traverse hierarchical or spatial structures while maintaining context across levels of abstraction (e.g., cohort-to-individual transitions). In immersive systems, such transitions are often manual, requiring users to switch between exocentric (overview) and egocentric (inside-out) views and to manage viewpoint, scale, and locomotion; this can introduce substantial cognitive and physical overhead in dense biomedical environments.

Empirical results highlight that frames of reference can differentially support analytic intent. Ng et al.\ report that cohort-level tasks are completed more efficiently in exocentric views than egocentric views in VR, while performance in egocentric views is strongly coupled to interaction usability~\cite{Ng2024ExoEgo}. This suggests that egocentric immersion can be valuable for focused inspection and embodied spatial memory, but only when navigation and interaction remain manageable.

These findings motivate intent-aware, AI-mediated multiscale control: instead of requiring analysts to manually manage scale and frame of reference, an assistant can infer analytic scope from interaction signals (e.g., selection, filtering, query breadth) and trigger appropriate viewpoint or scale transitions. This reframes navigation as a semantic problem tied to analytic intent, where automated view switching aims to reduce disorientation and preserve cognitive continuity across abstraction levels. Mechanisms for intent inference and real-time viewpoint control are discussed further in Section~\ref{sec:immersive-ai}.

\subsubsection{Selection, Filtering, and Precision Interaction}
\label{sec:selection-filtering-precision}
% \textit{E.g., selecting subsets (genes, cells), filtering by attributes or scores, decluttering dense visuals, note how conversational queries or gaze-driven selection can assist.}

Selection, filtering, and precision interaction capture tasks in which analysts specify subsets and constraints (e.g., selecting a cluster, filtering cohorts, thresholding edges, isolating regions of interest) to reduce analytic complexity and express intent. These operations are central to iterative analysis, not ancillary interactions.

This category also exposes modality-dependent constraints. Desktop environments support stable pointing and parameter entry, whereas immersive environments frequently rely on ray casting and mid-air manipulation that can be less stable for dense targets and more fatiguing. As a result, immersive systems often benefit from assistance mechanisms that translate imprecise input into reliable analytic operations via constraints, snapping, and disambiguation. One general strategy is intent-aware selection that fuses signals such as gaze, proximity, dwell time, and recent queries to infer the intended target and stabilize interaction.

Representative systems instantiate these principles in different ways. Dai et al.\ present Magic Portals, which preserve context while enabling fine-grained interaction with distant targets by bringing a focus region into comfortable reach~\cite{Dai2025MagicPortals}. Mishra et al.\ show that constrained interaction can make immersive molecular manipulation productive when actions are restricted to physically meaningful states and can be reused downstream~\cite{Mishra2024DockingVR}. Filtering further serves as a primary decluttering mechanism, often coupled with attention guidance in immersive settings; Doerr et al.\ analyze highlighting encodings for situated brushing and linking, noting trade-offs between findability and clutter as selection sizes grow~\cite{Doerr2024SituatedHighlighting}. In mixed-initiative systems, this category often becomes the interface between human hypothesis and computational support: users express constraints, and AI helps execute them precisely and transparently.

\subsubsection{Comparison and Differentiation}
\label{sec:comparison-differentiation}
% \textit{E.g., comparing experimental conditions or timepoints, aligning datasets, visualizing changes, note AI help like pattern discovery or narrative description, and immersive benefits (spatial overlays).}

Comparison and differentiation include contrasting conditions or timepoints, comparing cohorts, aligning representations (e.g., embeddings), and identifying outliers or structural shifts. These tasks depend on stable correspondence so that perceived differences reflect the data rather than interaction artifacts.

Immersive environments commonly support comparison through (at least) two complementary strategies. First, they can externalize similarity into spatial proximity, enabling exploratory differentiation via navigation in a similarity landscape (e.g., VROOM)~\cite{Lau2022}. Second, they can emphasize coordinated multiview comparison with synchronized interactions that preserve alignment across subjects or coordinate systems (e.g., NeuroCave)~\cite{Keiriz2017NeuroCave}. The former supports intuitive exploration and spatial memory, while the latter supports structured verification by minimizing contextual drift.

As AI assistance becomes more common, comparison tasks are also a natural substrate for pattern discovery and summarization: algorithms can propose salient contrasts, rank candidate differences, or generate brief descriptions that users can validate through aligned views and explicit filtering.

\subsubsection{Sensemaking and Hypothesis Development}
\label{sec:sensemaking-hypothesis}
% \textit{Sensemaking and hypothesis development tasks encompass the construction, refinement, and validation of mental models, including data contextualization, annotation, explanation, and the generation of biological hypotheses.}

Sensemaking and hypothesis development describe the interpretive work of constructing mental models, contextualizing observations, and iteratively refining questions into testable hypotheses. These tasks commonly progress from overview to isolating candidate structure, contextualizing with metadata or domain knowledge, externalizing interpretations (e.g., annotation), and testing alternatives via comparison, filtering, and follow-up queries.

Mixed-initiative assistance is most visible here: AI can summarize patterns, suggest candidate relationships, retrieve contextual information, or recommend alternative views and parameters. However, sensemaking support also carries higher epistemic risk than low-level assistance because narratives and recommendations can be persuasive; systems therefore benefit from preserving provenance, uncertainty, and auditability of suggestions and analytic steps.

Immersive environments can increase spatial capacity for externalizing intermediate results but may also fragment attention if too many elements compete in a 360-degree workspace. Workflow-oriented infrastructures such as XROps emphasize continuity by treating analysis as a configurable pipeline with preserved intermediate states and reversible exploration~\cite{Jeon2025XROps}. In the unified taxonomy, sensemaking and hypothesis development serve as the convergence point for the other task categories, with AI most valuable when it reduces friction without substituting unverifiable conclusions for scientific reasoning.

\subsubsection{Coordination and Collaborative Reasoning}
\label{sec:coordination-collaboration}
% \textit{Coordination and collaborative reasoning tasks involve shared interpretation, negotiation of meaning, role division, and maintenance of common ground among multiple analysts working within a visual analytics environment.}

Coordination and collaborative reasoning capture tasks required to establish common ground, divide labor, verify shared reference, and integrate partial findings into a negotiated interpretation. In life-science settings, collaboration is often necessary because expertise is distributed across disciplines and decisions frequently require consensus.

Prior work emphasizes that collaboration bottlenecks are often referential: when shared visual references degrade, teams may remain accurate but spend more effort grounding and verifying what is being referenced~\cite{Pettersson2009VisualReferences}. This motivates designs that support joint attention via shared pointers, legible deictic actions (e.g., pointing, gaze cues), and stable shared context.

Co-located immersive and hybrid systems instantiate these principles via shared spaces and artifacts (e.g., FIESTA)~\cite{Lee2021SharedSurfacesSpaces}, cross-device collaboration (e.g., Uplift)~\cite{Ens2021Uplift}, and personal overlays that preserve a shared reference while enabling individualized detail and tools (e.g., personal AR overlays)~\cite{Reipschlaeger2021PersonalAR}. AI assistance can further support coordination by tracking shared context, summarizing analytic state, and capturing provenance for hand-offs, but it can also undermine collaboration if it introduces divergent personalized views without clear reconciliation mechanisms. Treating coordination as a first-class task foregrounds that insights must be communicable, verifiable, and negotiable to become scientific conclusions.


\section{Visualization Modalities in Life-Science Visual Analytics}
% \textit{ Survey how each visualization environment supports or hinders analysis of biological “hairballs.”}
%\section{Visualization Modalities in Life-Science Visual Analytics}
\label{sec:visualization-modalities}
The unified task taxonomy introduced in Section~\ref{sec:task-foundations} provides a lens for characterizing analytical intent independently of any specific technological implementation. However, the manner in which these tasks are supported, constrained, or transformed is strongly influenced by the visualization modality in which analysis takes place. Different modalities afford distinct perceptual, spatial, and collaborative capabilities, shaping not only how tasks are performed but also which tasks are emphasized or become feasible. Rather than enumerating representative systems in a standalone section, we integrate system examples throughout the task-driven discussion that follows, using visualization modality and modes of AI assistance to contextualize design choices and trade-offs.

In this section, we examine how the task categories defined in Section~\ref{sec:task-foundations} manifest across visualization modalities, beginning with traditional 2D desktop environments and progressing through large displays and immersive systems. For each modality, we analyze how its characteristic affordances interact with algorithmic, adaptive, conversational, and immersive forms of AI assistance, highlighting systematic patterns in task support, design trade-offs, and open challenges. This modality-centric perspective provides the foundation for comparing AI-assisted visual analytics systems across heterogeneous analytical environments.

\subsection{Desktop 2D Environments}
% \textit{ The ubiquitous modality (e.g., Cytoscape-like tools). Discuss strengths (familiarity, reproducibility, integration with scripts) and limitations (clutter, limited spatial representation) for complex bio-data. NOTES: (1)Include some figures here from the papers illustrating heatmaps, bubblegrams,etc.; (2) Include mentions of force-directed graph examples like Cytoscape}
%\subsection{Desktop 2D Environments}
\label{sec:desktop-2d}
Desktop 2D environments remain the most common “everyday” interface for biological network and high dimensional data analysis. They are accessible, screen based, and easy to integrate into established computational pipelines. However, when desktop systems rely on classic node link diagrams as their primary representation, dense biological data quickly collapses into an unreadable hairball. Edge crossings and overplotting grow superlinearly with network size, and improvements in layout speed often only produce the same visual overload more efficiently.

A recurring design pattern across successful desktop systems is therefore semantic compression. Rather than attempting to render the full underlying structure, these systems compute interpretable structure first and visualize those summaries as the primary analytic objects. Typical forms of compression include clustering, aggregation, neighborhood construction, or redundancy reduction, with the resulting views taking the form of heatmaps, profile plots, density summaries, compact hierarchies, or reduced scatterplots. In effect, these tools refuse to draw the hairball and instead surface a smaller set of meaningful objects that better align with how biologists reason about results, such as modules, neighborhoods, enriched functions, or families of related entities.

This approach mirrors common wet lab practice, where raw instrument output is rarely acted upon directly. Instead, signals are summarized, compared, and grouped before hypotheses are formulated and validated.

At the algorithmic level, semantic compression typically combines aggregation, clustering, and redundancy reduction. In genomics, fluff and SeqPlots compress thousands of genomic regions into clustered heatmaps and aggregated signal profiles, enabling broad pattern discovery without explicit graph rendering \cite{Georgiou2016Fluff,Stempor2016SeqPlots}. For microbial community and multi omics data, Phinch uses taxonomic and metadata structure to drive interactive aggregated summaries rather than exposing raw complexity by default \cite{Bik2014Phinch}. AlignScape similarly compresses sequence similarity relationships into a self organizing map overview that supports “big picture first, details on demand” analysis \cite{FilellaMerce2024AlignScape}. For functional interpretation, GO Figure! reduces redundancy in enrichment results by grouping semantically similar GO terms and plotting representatives in a 2D semantic space, transforming long repetitive lists into interpretable summaries \cite{Reijnders2021GOFigure}.

The trade off of semantic compression is explicit. These approaches preserve global interpretability, dominant trends, and major differences between conditions, while sacrificing visibility of individual edges, rare elements, or minority patterns until users drill down. This trade off is often appropriate in biological discovery settings, where the initial question is “what are the major patterns” rather than “what is the exact path between two entities.” In pedigree analysis, VisAC uses collapsed pedigree representations to make consanguinity patterns analyzable without requiring users to trace every relationship edge by edge \cite{Borges2022VisAC}. In Cytoscape based workflows, clusterMaker2 similarly emphasizes cluster and matrix oriented summaries as a practical strategy for managing complexity and supporting downstream interpretation \cite{Utriainen2023clusterMaker2}.

From a task perspective (Section \ref{sec:task-categories}), semantic compression most strongly supports Comparison and Differentiation by enabling rapid visual comparison of conditions or cohorts through aggregated views. It also supports Sensemaking and Hypothesis Development by presenting stable, named structures such as clusters, modules, or neighborhoods that can be discussed, annotated, and tested. Compression can partially aid Navigation and Multiscale Orientation by providing a coherent overview layer, but it typically shifts Selection and Precision Interaction into a drill down workflow, where users first select an aggregate and then request the underlying elements. This design is effective when compression is reversible and traceable, and risky when summaries are opaque or irrecoverable.

Recent desktop systems in single cell and spatial biology extend the same compression first logic. TooManyCellsInteractive organizes large single cell datasets into a structured representation that supports progressive exploration rather than exhaustive point level rendering \cite{Klamann2024TooManyCellsInteractive}. For multiplexed tissue imaging, Visinity focuses on computing and exploring spatial neighborhood patterns instead of displaying raw, fully connected structures \cite{Xu2023Visinity}. Kandinsky similarly frames neighborhood analysis as a way to describe and interrogate cellular ecosystems, prioritizing computed structure over direct visualization of dense relationships \cite{Andrei2025Kandinsky}.

Finally, Transomics2Cytoscape provides an interpretability bridge for multi omics data by automating a layered, 2.5D visualization designed to keep complex trans omic relationships readable \cite{Nishida2024Transomics2Cytoscape}. While this approach introduces depth and layering, it remains a screen based desktop system, and its contribution here lies in the same compression first principle: computing and encoding structure so users can reason about it without confronting undifferentiated node link density.

Because semantic compression fundamentally changes what users can see and act on, its effectiveness should be evaluated along the axes introduced in \ref{sec:eval-alg-assistance}. In particular, evaluation must consider scalability and latency, representational fidelity, and auditability and provenance, including whether users can trace aggregate views back to the underlying biological evidence and parameter choices.

\subsection{Large Displays and Tiled Walls}
% \textit{ Wall-sized displays for collaborative, high-resolution analysis. Note strengths (multi-user collaboration, overview+detail at scale) and limitations (mostly manual interaction, no built-in AI guidance).}
\label{sec:large-displays}

Large displays and tiled walls support collaborative visual analytics by placing complex data in a shared, high-resolution workspace where teams can jointly view patterns, discuss findings, and maintain common ground. However, as data density and visual complexity grow, interaction based purely on direct manipulation (e.g., touch/click) becomes a bottleneck: limited reach, physical distance, and concurrent multi-user needs make it difficult to perform state-changing actions efficiently. From a task perspective, these constraints directly affect Navigation and Multiscale Orientation and Process Awareness and Provenance tasks (Section~\ref{sec:task-categories}), especially when collaborators must remain aligned on the evolving analytic state.

Speech has therefore emerged as an effective complement to touch for wall-scale systems. Talk to the Wall shows that users prefer speech for global operations (e.g., clearing filters, changing sort criteria, switching views) while reserving touch for precise, local interactions such as selecting specific items. Because speech commands can be issued from a distance, they reduce unnecessary movement and help teams preserve shared situational awareness; moreover, spoken commands externalize analytic intent, functioning as a lightweight coordination channel that supports alignment and collective process awareness (Section~\ref{sec:task-categories}) \cite{Leon2025TalkToTheWall}.

As visual analytics systems increasingly incorporate autonomous or semi-autonomous behavior, large displays also become shared spaces for oversight and supervision. Teams must monitor system behavior, interpret intermediate results, and intervene when outcomes appear incorrect or unexpected; wall-scale displays make analytic state legible to the group, while speech enables rapid high-level intervention (e.g., pausing, redirecting focus, resetting state) without requiring precise spatial interaction \cite{Leon2025TalkToTheWall}. Overall, these findings suggest that large displays should be designed less as scaled-up desktops and more as shared control surfaces that combine speech and touch to support group-level control, coordination, and real-time supervision of complex analyses.

\subsection{Immersive Environments (VR, AR, CAVE, Hybrid XR) and Spatial Unfolding}
% \textit{Fully or semi-immersive systems for 3D exploration (VR headsets, AR overlays, CAVE rooms). Highlight strengths (enhanced spatial understanding, embodied navigation) and limitations (user fatigue, precision issues without AI assistance).}
\label{sec:immersive-environments}

Immersive modalities expand the visual analytics workspace from a bounded screen to a spatial environment, enabling analysts to use depth, scale, and embodied viewpoint control to manage dense structure. This can reduce representational compression for intrinsically 3D domains and enable new strategies for decluttering abstract data, but it also makes navigation, selection stability, and attention management first-order concerns (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision}). The following subsubsections distinguish (i) intrinsically spatial data, where the Z axis is part of the signal, (ii) abstract omics and networks, where 3D is a design degree of freedom that must be disciplined, and (iii) AR/MR settings, where immersion becomes contextual augmentation to support situated analysis and collaboration (Section~\ref{sec:coordination-collaboration}).

\subsubsection{Intrinsic Spatial Data (Proteins and Anatomy): The Z Axis is Not Optional}
\label{sec:vr-intrinsic}

A substantial subset of life science data is intrinsically spatial: atoms occupy 3D coordinates in proteins, microscopy localizations form 3D point clouds, and anatomical reconstructions encode geometry that is itself the subject of study. In these settings, flattening to 2D discards depth relationships needed to reason about pockets, occlusion, adjacency, and pathways through space. Immersive VR can therefore function as a perceptual alignment tool, leveraging stereoscopic depth and embodied navigation to support Navigation and Multiscale Orientation (Section~\ref{sec:automated-view-switching}) and precision inspection (Section~\ref{sec:selection-filtering-precision}) in volumetric domains.

\paragraph{Proteins and docking: hairballs with pockets.}
For protein--ligand interactions, the core questions are geometric: whether a ligand fits, which trajectories are sterically plausible, and how conformations traverse transient channels. Mishra et al.\ present an interactive molecular dynamics in VR workflow in which users, protein experts familiar with ligand binding pockets, physically guide docking/undocking trajectories and then reuse the recorded trajectories and forces to parameterize subsequent simulation for binding free energy characterization~\cite{Mishra2024DockingVR}. CootVR similarly adapts macromolecular model building to VR via direct hand-driven manipulation and VR-specific visibility control over cluttered density and model geometry, including a controllable 3D clipping volume for focused editing in situ~\cite{Todd2021CootVR}. Together, these systems illustrate an assistance argument grounded in embodied geometric intuition rather than purely linguistic or predictive support: immersion preserves spatial truth while stabilizing precision tasks.

\paragraph{Microscopy and anatomy: point clouds, volumes, and scale.}
In single molecule localization microscopy, the data is a 3D point cloud whose density and self-occlusion can overwhelm 2D projections; vLUME demonstrates immersive navigation, selection, and spatial inspection for such localization datasets~\cite{Spark2020vLUME}. ConfocalVR similarly frames immersion as a way to explore 3D confocal microscopy volumes with depth cues and interactive viewpoint control matched to volumetric acquisition~\cite{Stefani2018ConfocalVR}. For neuroanatomy and cellular ultrastructure, DTBIA and Journey to the Centre of the Cell show how immersive analytics preserves spatial context and scale for reasoning about morphology, connectivity, and spatial organization~\cite{Yao2025DTBIA,Johnston2018Journey}.

\paragraph{Capability versus access: from high performance engines to web based VR.}
Intrinsic spatial analysis also motivates a continuum from high-performance rendering to low-friction access. VTX targets the rendering bottleneck to enable interactive visualization of extremely large molecular systems via GPU-oriented level-of-detail strategies~\cite{Rousset2025VTX}, while ProteinVR demonstrates browser-based VR to lower deployment friction for structural exploration and communication~\cite{Cassidy2020ProteinVR}. Across this spectrum, the common theme is that 3D perception is part of the scientific signal, not merely presentation.

\paragraph{Communication and public understanding.}
Intrinsic spatiality can also support communication when structure is the message; Corona VRus Coaster uses immersive interaction to convey viral form and spatial relationships to non-expert audiences~\cite{CalveloPineiro2025CoronaVRusCoaster}.

\subsubsection{Abstract Data (Genomics and Networks): The Hairball in the Headset}

Many life science datasets are expressed as graphs without intrinsic spatial coordinates (e.g., gene regulatory or coexpression networks). In these cases, immersion does not inherit a meaningful 3D frame from the phenomenon; depth becomes a design degree of freedom that can improve separation but can also amplify occlusion and edge clutter. Consequently, VR benefits abstract data primarily when it supports progressive disclosure and structured separation that serve Comparison and Differentiation (Section~\ref{sec:comparison-differentiation}) and Selection, Filtering, and Precision Interaction (Section~\ref{sec:selection-filtering-precision}), rather than when it simply adds Z to a dense node--link diagram.

\paragraph{Immersive 3D network layouts for de-cluttering and interactive analysis.}
NeuroCave illustrates disciplined use of 3D by imposing geometric constraints to reduce clutter: communities can be mapped onto Platonic solid faces to separate modules, with interactive rearrangement to expose dense regions. It also treats edge density as first-class, using on-demand edge reveal from a selected root node and GPU-accelerated edge bundling to mitigate crossings. Notably, NeuroCave is web-based and VR-compatible, demonstrating that zero-install delivery can coexist with immersive network analytics~\cite{Keiriz2018NeuroCave}. Earlier systems such as iCAVE provide a complementary baseline, emphasizing specialized 3D layouts and 3D edge bundling as essential mechanisms for de-cluttering biological graphs across desktop, stereoscopic, and CAVE-style settings~\cite{Liluashvili2017iCAVE}.

\paragraph{GeneNet VR: accessibility, performance, and the limits of dense network visualization.}
GeneNet VR targets accessibility on standalone hardware, reporting interactive exploration of gene--gene networks on an Oculus Quest-class headset while meeting a 72 FPS comfort target on networks with thousands of genes. The work underscores feasibility but also reinforces that performance alone does not eliminate the hairball: the authors emphasize selection, filtering, and scaling interactions and note the need to evaluate benefits for substantive analysis and knowledge discovery tasks~\cite{Fernandez2021GeneNetVR}.

\paragraph{Hardware trade-offs in standalone vs.\ web-based.}
Deployment choices shape which forms of interaction and assistance are realistic. SinglecellVR exemplifies a browser-mediated workflow intended to lower barriers for single-cell visualization in VR~\cite{Stein2021singlecellVR}. In contrast, CellexalVR argues that deeper analytic interaction depends on capabilities that lightweight viewers struggle to provide (e.g., high-resolution GPU-backed rendering and fully tracked hands), and frames VR as an expandable workspace supporting multiple reductions and in-session derivations such as differential expression and trajectory-related views~\cite{Legetth2021CellexalVR}.

\paragraph{Anchoring abstract omics to physical reality.}
Spatial transcriptomics shifts immersion toward physically meaningful coordinates. VR Omics supports multi-slice spatial transcriptomics exploration in 3D with optional VR integration, leveraging alignment and spatial context to interpret molecular patterns~\cite{Bienroth2025VROmics}.

\paragraph{Immersive VR for cohort separation and layer disentanglement.}
Several systems show that immersion can be effective for cohort separation and layer disentanglement even when the underlying data are abstract. VROOM uses an immersive similarity space for oncology cohorts, linking 3D clusters to coordinated genomic panels (e.g., heatmaps) to separate groups and drill down without collapsing everything into a single overplotted view~\cite{Lau2022VROOM}. Conceptual work on immersive multilayer animal behaviour networks similarly emphasizes separating and manipulating layers in 3D to reduce overlap and support comparison~\cite{Feyer2024AnimalBehaviourImmersive}.

Together, these examples indicate that VR is a conditional advantage for abstract life-science data: when paired with structured layouts, progressive disclosure, and explicit separation of layers or cohorts, the headset becomes a decluttering instrument that supports comparative reasoning (Section~\ref{sec:comparison-differentiation}). When VR merely adds depth to unconstrained node--link diagrams, occlusion and perspective ambiguity can worsen the hairball, shifting effort from interpretation toward perceptual triage.

\subsubsection{Augmented and Mixed Reality: Situated Analytics}
\label{sec:ar-mr-situated}

Augmented and mixed reality (AR/MR) support a situated layer of life science analytics in which views are integrated into the physical laboratory context rather than replacing it. This orientation is well matched to hybrid workflows where teams collaborate around shared artifacts while individuals require private controls, annotations, and alternative views, directly implicating Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}) and Sensemaking and Hypothesis Development (Section~\ref{sec:sensemaking-hypothesis}). Reipschl\"{a}ger et al.\ formalize this model by combining a shared large interactive display with personal head-worn AR overlays, allowing individualized views and tools without disrupting the shared reference frame~\cite{Reipschlaeger2021PersonalAR}.

Once views move into the environment, spatial layout becomes a determinant of readability and cross-view reasoning. Wen et al.\ study multi-view layout in immersive visualization and propose an automatic adaptation strategy using a cylindrical reference frame and force-directed optimization to maintain visibility and balanced view-to-user and view-to-referent distances, improving performance on cross-view tasks relative to alternative paradigms~\cite{Wen2023ViewLayout}. Mapping abstract marks back to physical referents also becomes central: Doerr et al.\ propose situated brushing and linking, where brushing in a situated scatterplot triggers highlighting of corresponding referents, and show trade-offs between simple high-contrast encodings (low error) and more elaborate guidance that can introduce clutter as selection sizes grow~\cite{Doerr2024SituatedHighlighting}. This directly operationalizes Selection, Filtering, and Precision Interaction in situated settings (Section~\ref{sec:selection-filtering-precision}).

MR systems further demonstrate domain-specific pipelines that keep analysts present in their workspace while enabling volumetric inspection. Iakab et al.\ present an end-to-end 3D MALDI imaging platform culminating in an MR tool for exploring volumetric spatial omics with video pass-through and hand-tracked interaction~\cite{Iakab2025FromSampleToMixedReality}. When physical deployment is difficult, Iglesias et al.\ approximate situatedness by overlaying augmented visualizations on a photorealistic reconstruction of a real environment in VR, preserving recognizability while integrating feature extraction and reconstruction workflows~\cite{Iglesias2021EnhancedPhotorealistic}. Across these works, the situated layer reframes immersion as contextual augmentation: keeping analytic reasoning anchored to the social and physical realities of lab work while providing algorithmic support for layout, linking, and attention guidance.

\section{AI Assistance in Life-Science Visual Analytics (Vertical Dimension of the Conceptual Model)}

Whereas Section~\ref{sec:visualization-modalities} characterizes \emph{where} biological visual analytics happens: across desktops, large displays, and immersive environments, this section characterizes \emph{how} analysis is augmented. We use \emph{AI assistance} broadly to include machine learning, optimization, and rule-based automation that intervenes in the analytic loop, whether by transforming data before visualization, adapting the interface during interaction, or mediating communication between analyst and system.

To make this landscape comparable across modalities, we organize prior work by assistance type rather than by display. We survey four recurring roles: \emph{algorithmic assistance} for structure extraction and visual simplification (e.g., layouts, clustering, embeddings, multiscale abstraction); \emph{adaptive assistance} that uses interaction traces and feedback to personalize views, recommend actions, or reconfigure representations as intent changes; \emph{conversational assistance} that introduces natural language for querying, steering, and explanation; and \emph{immersive AI assistance} that embeds intelligence directly into XR interaction (e.g., guided navigation, occlusion-aware visibility control, gaze/gesture fusion, and precision support).

These modes are often combined, and their relative importance depends on visualization modality and the task categories introduced in Section~\ref{sec:task-categories}. Accordingly, this section summarizes key mechanisms for each assistance type and highlights how they redistribute task load across navigation, comparison, selection, sensemaking, and collaboration. It also foregrounds recurring challenges, maintaining analyst agency, mitigating automation-induced bias, and preserving reproducibility when assistance is adaptive or conversational, which we revisit in later design and evaluation discussions.



% \section{AI Assistance in Life-Science Visual Analytics (Vertical Dimension of the Conceptual Model)}
% %  Survey the roles of AI assistance types across all visualization modalities.
% \subsection{Algorithmic Assistance (Foundational AI for Visual Analytics)}
% \textit{ Pre-computed or on-demand computational techniques (clustering, dimensionality reduction, layout algorithms, etc.) that enhance scalability and pattern detection. Strengths (objective structure finding, reproducibility) vs. limitations (static, not user-adaptive).}
%  Survey the roles of AI assistance types across all visualization modalities.

\subsection{Algorithmic Assistance (Foundational AI for Visual Analytics)}
% \textit{Pre-computed or on-demand computational techniques (clustering, dimensionality reduction, layout algorithms, sparsification, etc.) that enhance scalability and pattern detection. Strengths include reproducibility and the ability to expose latent structure, limitations include distortion, opacity, and weak alignment with user intent when used as a one-shot preprocessing step.}

Algorithmic assistance is the most “foundational” form of AI in visual analytics because it reshapes the analytical substrate before any interaction happens. In life-science workflows, this reshaping is often what determines whether a dataset is even navigable, for example whether a single-cell atlas becomes a traversable landscape or remains a dense, uninterpretable cloud, whether a knowledge graph becomes a readable scaffold or stays a hairball. We organize algorithmic assistance around three recurring mechanisms: (i) \emph{embedding and dimensionality reduction}, which moves complexity into a latent geometry, (ii) \emph{sparsification and backbone extraction}, which removes edges while claiming to preserve specific structural guarantees, and (iii) \emph{semantic aggregation and abstraction}, which replaces redundant pathway and ontology outputs with a compact conceptual map. Across all three, the key question is not only “does it look cleaner,” but “what truth claims still hold after the reduction.”

\subsubsection{Embeddings / Dimensionality Reduction (“move complexity into latent geometry”)}

% \noindent\textbf{Mechanism definition (what the algorithm does).}
Embeddings and dimensionality reduction construct a low-dimensional coordinate system whose distances and neighborhoods are intended to stand in for high-dimensional similarity. In methods like SNE and t-SNE, the embedding is the solution to an optimization problem that attempts to preserve local neighborhood relations under a compressed geometry, producing a map that users can navigate and interpret visually \cite{hinton2002sne,vandermaaten2008tsne}.

% \noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
The benefit is immediate decluttering, the “hairball” becomes a spatial field where proximity approximates similarity. The cost is that preservation is partial and scale-dependent, local neighborhoods can be emphasized at the expense of global topology, and visually crisp cluster boundaries can be artifacts of hyperparameters, density variation, or confounds rather than biology. In other words, embeddings reduce visual complexity by relocating it into a learned geometry whose distortions can be hard to see.

Embeddings most directly support \textbf{Navigation and Multiscale Orientation} by turning search and overview into spatial movement through a latent landscape, and they support \textbf{Comparison and Differentiation} when clusters and gradients correspond to stable biological structure. However, they can actively harm \textbf{Sensemaking and Hypothesis Development} if users treat the map as ground truth without diagnostics, because interpretation becomes anchored to geometry that may not be globally trustworthy.

The classic SNE and t-SNE line of work formalizes the core promise, neighborhood structure in the original space is approximately preserved in a 2D or 3D map that users can inspect and traverse \cite{hinton2002sne,vandermaaten2008tsne}. More recent biological embedding work increasingly treats verification as a first-class requirement, for example, PARE operationalizes counterfactual checking by producing covariate-adjusted distance structures so analysts can ask what changes when batch or other confounds are removed \cite{chen2024pare}, and Haisu explicitly incorporates hierarchical intent into nonlinear dimensionality reduction to better align embeddings with multiscale biological structure \cite{vanhorn2022haisu}. Domain-specific models further show how “the embedding” is often not a generic scatterplot input, but an algorithmic object that encodes priors and structure: PAST learns latent features for spatial transcriptomics by combining spatial graphs with reference information, producing embeddings that improve downstream spatial domain identification and related tasks \cite{Li2023PAST}, while PoincaréDMT adopts hyperbolic geometry to better represent hierarchical and branching structure in single-cell data, pairing geometric preservation goals with attribution methods for marker interpretation \cite{Xu2025PoincareDMT}. Taken together, these works support a design stance of “trust, but verify the embedding,” where the visualization is only as reliable as the stability, confound control, and provenance of the learned geometry.

% \noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
Embedding-based assistance should therefore be evaluated along the \ref{sec:eval-alg-assistance} axes, scalability of computation and interactivity, fidelity of preserved neighborhoods and global structure, and auditability through stability diagnostics, confound tests, and end-to-end provenance.

\subsubsection{Sparsification and Backbones (“what guarantees survive?”)}

% \noindent\textbf{Mechanism definition (what the algorithm does).}
Sparsification reduces a dense graph by removing edges to obtain a backbone, a subgraph intended to retain “important” structure while discarding redundancy. Unlike visual decluttering applied at render time, backbone extraction changes the graph itself, often guided by structural criteria such as preserving shortest-path geometry, connectivity, or statistically significant weighted edges.

% \noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
Sparsification is not just an optimization, it is an epistemic commitment about which relations matter. A backbone can preserve particular guarantees, for example, approximate reachability structure or key transmission pathways, but it necessarily sacrifices completeness, including weak ties that might be biologically meaningful in specific contexts. The central trade-off is therefore between interpretability and coverage, and that trade-off must be explicit.

% \noindent\textbf{Task-category mapping (Section~\ref{sec:task-categories}).}
Backbones most directly enable \textbf{Selection, Focus, and Precision Interaction} because they reduce the candidate space of edges and neighborhoods to something a user can actually inspect, filter, and annotate. They also support \textbf{Navigation and Multiscale Orientation} by making global structure traversable, and \textbf{Comparison and Differentiation} when different backbones expose condition-specific connectivity patterns. For \textbf{Sensemaking and Hypothesis Development}, sparsification only helps when guarantees and provenance are visible, otherwise hypotheses may be built on edges that survived for algorithmic reasons the user does not understand.

% \noindent\textbf{Evidence paragraph (2--4 anchor + 2--6 supporting papers).}
Comparative backbone work makes clear that different sparsification rules preserve different properties, and no single method is universally “correct,” the choice determines what structural truths remain legible \cite{Yassin2025BackboneExtraction}. In an applied biomedical setting, myAURA operationalizes this perspective by sparsifying a multilayer biomedical knowledge graph using a metric-backbone approach to yield a far smaller, more interpretable structure for epilepsy management, while treating the retained edges as the backbone of meaningful relations for inference, recommendation, and exploration \cite{Correia2026myAURA}. Importantly, this is exactly where sparsification becomes a scientific claim rather than a convenience, the system is making a statement about which edges are primary enough to drive interpretation and downstream action. This framing generalizes beyond epilepsy, dense biological interaction graphs and integrated knowledge graphs often require a backbone layer before any interactive visual analysis is feasible, but the backbone must be defensible relative to the analyst’s questions.

% \noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
Backbone extraction should be evaluated in \ref{sec:eval-alg-assistance} terms as a coupled scalability, fidelity, and auditability problem, can it be computed fast enough for interactive use, what structural properties are preserved or broken, and can users inspect what was removed and why.

\subsubsection{Semantic Embeddings and Abstraction for Pathway Results (“compress redundancy into concepts”)}

% \noindent\textbf{Mechanism definition (what the algorithm does).}
A large fraction of life-science “hairballs” are not only node link graphs, they are redundant, overlapping lists of pathways, gene sets, and ontology terms produced by enrichment and differential analysis pipelines. Semantic abstraction methods address this by embedding pathway terms into a vector space, clustering them by similarity, and then visualizing cluster representatives or conceptual neighborhoods rather than every term individually.

% \noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
These methods preserve semantic relatedness and reduce redundancy, helping users see themes rather than duplicates. The sacrifice is that gene-level mechanistic detail and fine-grained distinctions between closely related pathways can be obscured when terms are merged or abstracted, and the embedding model itself introduces a new layer of potential bias.

% \noindent\textbf{Task-category mapping (Section~\ref{sec:task-categories}).}
Semantic aggregation strongly supports \textbf{Comparison and Differentiation} when analysts contrast conditions and need to see which functional themes diverge, and it supports \textbf{Selection, Focus, and Precision Interaction} by reducing thousands of terms to a manageable set of representative candidates. It also directly accelerates \textbf{Sensemaking and Hypothesis Development}, because it provides a structured narrative substrate, a compact “map of mechanisms” that can be cross-checked against underlying genes and evidence.

% \noindent\textbf{Evidence paragraph (2--4 anchor + 2--6 supporting papers).}
PAVER exemplifies embedding-driven consolidation for pathway enrichment output, embedding pathway terms, clustering them, and selecting representative pathways to produce concise visual summaries instead of long redundant lists \cite{ODonovan2024PAVER}. Mondrian Map pushes the abstraction further by using language model embeddings to spatially arrange pathway tiles in a Mondrian-style layout, encoding differential activity through size and color and highlighting limited crosstalk connections, explicitly replacing dense node link representations with a structured conceptual surface \cite{AlAbir2024MondrianMap}. Both systems illustrate a key algorithmic-assistance pattern for “hairballs to hypotheses,” when mechanistic interpretation is the goal, it can be more faithful to show an audited summary of functional concepts than to overwhelm users with every pathway term and every edge.

% \noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
These abstractions should be evaluated in \ref{sec:eval-alg-assistance} terms with scalability to large enrichment outputs, fidelity of semantic grouping relative to biological ground truth or expert judgment, and auditability that exposes which genes and databases support each tile or cluster, and which embedding model and version produced the geometry.

\subsection{Adaptive Assistance}
% \textit{Interfaces that adjust in real-time to user behavior or data context (e.g., focus highlighting, recommended next steps, level-of-detail adjustments). Note how this reduces cognitive load and speeds analysis, and discuss challenges (user modeling complexity, potential opacity).}

Adaptive assistance adapts visualization or interaction in response to the user and context, grounded in three capabilities: (i) \emph{user modeling} to anticipate interaction patterns and detect exploration bias; (ii) \emph{intent understanding} to infer higher-level goals from interaction traces (e.g., learned models over structured logs); and (iii) \emph{proactive guidance} that recommends what to examine next (insights) and what to do next (actions). We use DataSite as an exemplar of proactive insight recommendation, deep-learning interaction recommenders as exemplars of action suggestion, and comparative work on user-modeling techniques to elevate bias detection as a first-class requirement~\cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation,Ha2022UserModeling,Wang2024GNNIntent}.

While adaptation can reduce cognitive burden, it can also steer exploration and create ``filter bubble'' dynamics in which recommendations narrow what is seen and, consequently, what gets concluded. Adaptive systems therefore benefit from explicit provenance: why a recommendation is made, which signals were used (e.g., interaction history, inferred intent, data priors), and how to override it (disable personalization, request diversity, lock a view/facet/scale, or widen the search space). Bias detection should monitor when adaptation concentrates attention too early, and guidance policies should trade off relevance with coverage to avoid premature convergence~\cite{Ha2022UserModeling,Steichen2019TowardsAdaptiveInfoVis}.

Evaluation is also audience-dependent: ``good guidance'' differs when judged by visualization experts (appropriateness, soundness of rationale, risk of biasing) versus end users (in-situ usefulness while solving tasks)~\cite{Ceneda2024HeuristicDualEvaluation}. Relative to the task categories in Section~\ref{sec:task-categories}, adaptive assistance supports Navigation and Multiscale Orientation via viewpoint/scale guidance and focus routing, and Selection/Filtering/Precision via intent-driven filtering and suppression or recommendation of items~\cite{Wang2024GNNIntent}. For Sensemaking and Hypothesis Development, insight recommendation can accelerate early hypothesis formation, but should surface uncertainty, alternatives, and overrides to reduce premature convergence~\cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation}.

\subsection{Agentic Orchestration (Conversational Interfaces for Autonomous Analytics)}
\label{sec:agentic-orchestration}

As biological datasets grow in size and complexity, step-by-step manual interaction becomes an increasingly poor match for analysis that requires long sequences of filtering, parameter tuning, and view switching. These procedural demands can distract from scientific reasoning and make it harder to maintain continuity of analytic intent. In this setting, natural language interfaces (NLIs) are better understood not as one-shot question askers, but as mechanisms for initiating, steering, and supervising analytic workflows---supporting Sensemaking and Hypothesis Development (Section~\ref{sec:sensemaking-hypothesis}), Comparison and Differentiation (Section~\ref{sec:comparison-differentiation}), and the operational substrate of Navigation and Multiscale Orientation and Selection/Filtering/Precision interaction (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision})~\cite{Jia2024LightVA,Chen2024ProactiveVA}.

Earlier NLI-for-vis work emphasized translating utterances into specific visual operations (e.g., generating a chart or applying a filter)~\cite{Wang2024DomainBridge}. While this lowers interaction barriers, users must still specify each step. More recent systems shift toward goal-driven execution: users express an objective and the system plans and carries out a sequence of coordinated actions. LightVA exemplifies this framing by treating analysis as a planning problem, decomposing objectives (e.g., comparing groups or exploring trends) into ordered steps such as data selection, transformation, visualization, and statistical comparison~\cite{Jia2024LightVA}. Making the plan and intermediate states explicit also supports oversight and shared understanding, which is critical for Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}).

This orchestration model aligns with scientific practice, where analysts reason in terms of aims and workflows rather than isolated interface commands. PhenoAssistant applies this approach in a biological setting by coordinating multiple specialized agents across a phenotyping pipeline, shifting the user role from micromanaging operations toward supervising progress, inspecting intermediate results, and redirecting analysis when needed~\cite{Kim2024PhenoAssistant}. Conversation remains central, but primarily as a means to refine goals and assumptions as evidence accumulates; PhenoFlow and CausalChat illustrate iterative dialogue for progressively narrowing cohorts, revising causal models, and exploring alternatives, directly linking conversational interaction to Selection/Filtering and hypothesis refinement (Sections~\ref{sec:selection-filtering-precision} and~\ref{sec:sensemaking-hypothesis})~\cite{Kim2024PhenoFlow,Guo2024CausalChat}.

Some systems add limited proactivity, suggesting next steps or flagging potential issues without explicit prompting (e.g., recommending additional comparisons or highlighting unusual patterns)~\cite{Chen2024ProactiveVA}. While this can reduce cognitive burden, it increases the importance of transparency, reversibility, and user control to avoid over-steering. Overall, these examples suggest that conversational assistance in visual analytics is evolving into agentic orchestration: language is used to manage multi-step analytic work, offloading procedural complexity while keeping users responsible for interpretation and decisions. This shift has direct implications for evaluation and trust, as discussed in Section~\ref{sec:conversational-assistance}.

\subsection{Immersive AI Assistance: Intelligence Embedded in XR Analytics}
\label{sec:immersive-ai}

Immersive environments (VR, AR, CAVE) provide a large spatial workspace for visual analytics, but life-science data quickly exposes interaction limits. Many systems still rely on controller-based ray casting and skeuomorphic metaphors (virtual desks, dashboards, literal tools) to reduce the learning curve; for example, VROOM supports ontology-graph editing with virtual scissors and glue~\cite{Vinnikov2022VROOMOntology}. However, for dense biological point clouds and networks, naive pointing and mid-air manipulation can be slow, error-prone, and fatiguing (``gorilla arm''), motivating immersive AI assistance in which the system actively mediates between noisy human input and the data model. In task terms, this assistance primarily stabilizes Navigation and Multiscale Orientation and Selection/Filtering/Precision interaction (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision}) while supporting downstream sensemaking (Section~\ref{sec:sensemaking-hypothesis}).

A useful lens for XR interaction is the contrast between \emph{hard} and \emph{soft} magic: hard-magic systems have explicit rules and predictable outcomes, whereas soft-magic systems are intentionally ambiguous~\cite{SandersonFirstLaw}. Wizualization applies this framing to immersive analytics by treating gestures and speech as a rule-governed grammar for constructing and transforming views, rather than as navigation through a virtual office~\cite{Batch2024Wizualization}. When interaction has clear syntax and semantics, users can form stable mental models and the system can provide disambiguation, suggestions, and recovery when input is partial or imprecise, improving process continuity during exploration.

For biology, this implies a shift from controller-driven commands toward intent-based interaction that fuses signals such as gaze, reach, and data constraints to infer goals (e.g., select a cluster, follow a trajectory, dock a ligand) and execute them safely. Existing systems illustrate three complementary assistance layers. \emph{Navigational assistance} can steer viewpoint through clutter: Nanotilus generates inside-out guided tours through crowded molecular environments by planning traversable camera paths and applying view-dependent sparsification to manage occlusion~\cite{Alharbi2023Nanotilus}. \emph{Motor and physics assistance} can stabilize manipulation by constraining actions to valid targets: in immersive molecular docking, Mishra et al.\ show that human-guided VR manipulation, constrained by physically meaningful forces and geometry, yields useful docking and unbinding trajectories that are reused to accelerate subsequent simulations~\cite{Mishra2024DockingVR}; for selection in room-scale point clouds, Magic Portals bring distant regions into comfortable reach (with optional haptic confirmation), reducing jitter and fatigue while preserving context~\cite{Dai2025MagicPortals}. Finally, \emph{attention assistance} is critical in 360$^\circ$ workspaces where relevant items may be out of view: Doerr et al.\ compare highlighting techniques for situated brushing and linking, showing how cues can guide attention from abstract views to concrete referents while also becoming clutter as selection sizes grow~\cite{Doerr2024SituatedHighlighting}. Beyond biology, VR training for SONAR interpretation similarly demonstrates both benefit and risk: an egocentric conformal overlay improved speed and accuracy but could increase reliance when removed~\cite{Salamon2025TrainingSONAR}.

Collectively, these works suggest that effective immersive interfaces are less about adding more virtual tools and more about a cooperative ``copilot'' that infers intent and manages degrees of freedom by fusing multimodal signals (gaze, proximity, gesture, and model constraints) to choose viewpoints, constrain actions, and direct attention. This framing also motivates the role of haptics (Section~\ref{sec:visceralization}): tactile feedback can provide an additional confirmation channel for selection and manipulation, helping immersive assistance feel precise rather than fragile~\cite{Dai2025MagicPortals}.

\subsection{Data Physicalization and Visceralization: From Visualizing to Visceralizing}
\label{sec:visceralization}

Immersive analytics is often framed as ``more space for more charts,'' but XR can also restore aspects of physical reality that matter in the life sciences: scale, density, crowding, and proximity. Many biological phenomena can be abstracted mathematically, yet analysts still reason about them through embodied intuitions (e.g., ``how large,'' ``how dense,'' ``how close''). In this sense, immersion that remains purely optical can underserve Sensemaking and Hypothesis Development (Section~\ref{sec:sensemaking-hypothesis}) and Navigation and Multiscale Orientation (Section~\ref{sec:automated-view-switching}), where maintaining scale and context is part of the analytic signal.

Lee et al.\ introduce \emph{data visceralization} to describe VR experiences that reconnect quantitative data to physical meaning through embodied scale and presence, mitigating how abstraction can sever a user’s sense of what units correspond to in the world~\cite{Lee2021DataVisceralization}. When a representation preserves a one-to-one relationship between quantity and spatial extent where feasible, ``how big'' and ``how fast'' can be perceived differently than in purely symbolic encodings. For life-science visual analytics, this suggests that visceral scale can function as a first-class analytic channel (e.g., for interpreting cellular crowding, sampling density, or anatomical extent), complementing conventional views and strengthening qualitative intuition during comparison and interpretation (Sections~\ref{sec:comparison-differentiation} and~\ref{sec:sensemaking-hypothesis}).

A second step beyond visual immersion is to reintroduce aspects of \emph{touch} and resistance. While full haptics remain costly, especially in multi-user settings, XR can sometimes exploit \emph{pseudo-haptics}, where carefully designed visual feedback induces haptic illusions. Weiss et al.\ study such illusions in co-located collaborative VR by manipulating the apparent shape and size of a shared object during handover, showing both promise and risk: users adapt to the illusion, but visuo-haptic mismatches can degrade performance and experience, and asymmetric roles can amplify these effects~\cite{Weiss2025HapticIllusions}. For collaborative life-science analysis, this directly implicates Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}): ``adding touch'' must be conservative, consistent across users, and auditable enough to avoid confusion or mistrust during shared interpretation.

Finally, embodied understanding need not remain inside XR at all. \emph{Data physicalization} turns data into tangible artifacts that can be handled, shared, and discussed without headsets. Protein ORIGAMI exemplifies this approach by converting peptide sequences into printable templates for folded paper models, with residue properties encoded via color and geometry~\cite{Reisser2018ProteinORIGAMI}. While not aimed at computational novelty, it highlights that for some tasks, particularly teaching, communication, and face-to-face sensemaking, a lightweight physical object can be the most effective ``display'' (Sections~\ref{sec:sensemaking-hypothesis} and~\ref{sec:coordination-collaboration}).


%  Discuss how combining certain modalities with certain AI modes yields benefits or challenges (e.g., 2D + conversational for accessibility, large display + adaptive for collaboration, VR + immersive-AI for navigation). Emphasize unexplored modality–AI combinations as opportunities.
%  (Transition: argue that as data complexity grows, AI assistance is becoming essential, leading into evaluation considerations in Section~6.)
\subsection{Cross-Modal Synergies and Tensions}
\label{sec:cross-modal-synergies}

Across the surveyed literature, effective systems rarely rely on a single modality or a single assistance mechanism; instead, they pair modalities with assistance types that compensate for bottlenecks in key task categories (Section~\ref{sec:task-categories}). Desktop interfaces remain unmatched for precise control and reproducible parameterization, and can become more accessible when conversational or intent-based interaction reduces configuration friction, supporting Selection/Filtering/Precision interaction and Sensemaking (Sections~\ref{sec:selection-filtering-precision} and~\ref{sec:sensemaking-hypothesis}). Large displays and co-located environments amplify group sensemaking but are constrained by shared reference and coordination overhead, motivating adaptive and attention-oriented assistance that maintains alignment and supports personal overlays without breaking shared context (e.g., hybrid wall+AR)~\cite{Reipschlaeger2021PersonalAR} and collaborative immersive workspaces that externalize analytic artifacts~\cite{Lee2021SharedSurfacesSpaces}. In immersive VR/AR, where the stereo dividend can improve perception but navigation and selection are costly, immersive-AI assistance is often necessary: guiding transitions between overview and inspection~\cite{Ng2024ExoEgo}, steering users through dense geometry~\cite{Alharbi2023Nanotilus}, stabilizing precise interaction at room scale~\cite{Dai2025MagicPortals}, and directing attention in 360$^\circ$ workspaces~\cite{Doerr2024SituatedHighlighting}. Together, these examples suggest that modality and assistance are best treated as a coupled design system rather than independent add-ons.

Cross-modal combinations also introduce tensions that may not surface when components are evaluated in isolation. Personalization can fracture collaboration if users receive different overlays, recommendations, or highlights, widening the referential gap that already challenges shared analysis~\cite{Pettersson2009VisualReferences} and undermining Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}). Adaptive and conversational assistance can threaten reproducibility and auditability when system state changes based on prior interactions or when explanations are not traceable to computations, directly impacting Process Awareness and Provenance and hypothesis validation (Section~\ref{sec:sensemaking-hypothesis}). Cross-device ecosystems further increase engineering and provenance burden because synchronizing views, selections, and algorithmic stages across browsers, desktops, and headsets requires explicit workflow/state management, as emphasized by web-based and pipeline-oriented architectures~\cite{CortesRodriguez2024MolecularWebXR,Borowski2025DashSpace,Jeon2025XROps}.

These synergies and tensions highlight under-explored opportunities, including conversational guidance tightly integrated with immersive navigation to reduce the navigation tax, adaptive assistance that explicitly optimizes joint attention in co-located collaboration, and workflow-level designs that treat multiresolution abstraction and streaming as first-class assistance rather than implementation detail. As data complexity and heterogeneity grow, such mixed-initiative cross-modal designs will become increasingly necessary, motivating the evaluation focus of Section~\ref{sec:eval-landscape}: measuring not only whether assistance improves task performance, but whether it strengthens scientific reasoning without compromising trust, provenance, or collaboration.


% \section{Evaluation Landscape}
% When reviewing visualizations, it is important to consider both how effectively they support analytical tasks and how well they align with users’ cognitive processes. Isenberg et al \cite{Isenberg2013ReviewEvaluatingVis} highlight that visualization evaluation should go beyond surface‐level usability metrics to examine how design choices influence interpretation, bias, and decision quality.


% \subsection{Evaluation Across Visualization Modalities}
%  Discuss evaluation methods for different modalities.
\section{Evaluation Landscape}
\label{sec:eval-landscape}

When reviewing visualizations, it is important to consider both how effectively they support analytical tasks and how well they align with users’ cognitive processes. Isenberg et al.~\cite{Isenberg2013ReviewEvaluatingVis} emphasize that evaluation should go beyond surface level usability metrics to examine how design choices influence interpretation, bias, and decision quality.

\subsection{Evaluation Across Visualization Modalities}
\label{sec:eval-across-modalities}

A recurring pitfall in evaluating immersive systems is treating the comparison as a binary choice: either a conventional 2D desktop view or a headset based 3D view. In practice, there is an important middle ground. Desktop systems can already capture some of the benefits often attributed to immersion by adding depth cues and controlled 3D interaction on a flat display. This creates a useful baseline for evaluation: if a headset system claims an advantage, it should ideally outperform not only 2D scatterplots, but also strong desktop designs that include shading, depth cues, and rotation.

This is especially relevant for life science workflows, where many “high dimensional” datasets (for example cell embeddings or multi feature cohort representations) are explored through low dimensional projections. The evaluation question is not only whether VR or AR helps, but whether the benefit comes from immersion itself, or from more basic factors such as increased depth cues, motion based viewing, and better separation of overlapping structures.

\subsubsection{2D Desktop and Pseudo 3D Evaluation}
\label{sec:eval-2d-pseudo3d}

A common visualization argument is that 2D is the safer default: it avoids occlusion, supports fast interaction, and enables efficient Selection/Filtering/Precision interaction and externalization (Section~\ref{sec:selection-filtering-precision}). However, several studies show that carefully introduced 3D cues on the desktop can improve cluster perception and group separation without a headset. This ``2.5D'' compromise uses depth only where it increases clarity, while keeping interaction costs closer to conventional desktop analytics.

Wang and Mueller challenge the assumption that 3D is automatically harmful for cluster analysis by showing that shaded, rotatable 3D renderings can make dense point-cloud structure more legible on standard displays~\cite{WangMueller2014Does3D}. Rotation provides motion parallax and enables users to look ``around'' structures, reducing apparent overlap relative to a single flattened view. Poco et al.\ similarly compare 2D versus 3D multidimensional projections on a standard screen and report higher precision for neighborhood-based similarity metrics in 3D; their user study suggests that some tasks are answered more reliably and confidently in 3D, albeit sometimes with increased time due to interaction overhead~\cite{Poco2011Framework3DProjections}. For evaluation, this motivates reporting accuracy, time, and confidence together when assessing Navigation and Multiscale Orientation and Comparison/Differentiation benefits (Sections~\ref{sec:automated-view-switching} and~\ref{sec:comparison-differentiation}), rather than time alone.

Alper et al.\ provide a complementary pseudo-3D strategy for graphs: preserve a 2D layout but use stereoscopic depth as a highlighting channel to separate a selected subset from the background~\cite{Alper2011StereoscopicHighlighting}. Their results indicate that stereoscopic depth combined with conventional highlighting improves performance, and that full 3D layouts do not necessarily outperform strong 2D baselines with effective emphasis. For life-science networks and embeddings, these findings imply that desktop baselines should include both 2D and pseudo-3D variants when evaluating immersive systems, to isolate what XR uniquely contributes beyond additional separation cues.

\subsubsection{Large-Display and Collaborative Evaluation}
\label{sec:eval-large-collab}

Large-display visualization is often evaluated with individual metrics (time, error, workload). However, once a visualization becomes a \emph{shared reference} for a co-located team, a different bottleneck dominates: whether collaborators can establish and maintain \emph{joint attention}: confidence that they are referring to the same object at the same time. Pettersson et al.\ characterize this as the problem of \emph{shared visual references}: when mutual verification is difficult, teams remain accurate but become less efficient because effort shifts from analysis to grounding, clarification, and deictic repair~\cite{Pettersson2009VisualReferences}. This directly impacts Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}) and downstream Sensemaking and Hypothesis Development (Section~\ref{sec:sensemaking-hypothesis}).

Pettersson et al.\ quantify this cost by comparing integrated views with partitioned views that reduce clutter but degrade shared references: even when tasks required only minimal shared comparison, reduced shared reference significantly decreased efficiency while error remained low, reflecting increased coordination overhead~\cite{Pettersson2009VisualReferences}. Accordingly, large-display evaluation should augment classic measures with collaboration-centric outcomes such as time-to-ground a reference, clarification frequency, deictic gesture rate (pointing, gaze following), and conversational breakdowns/repairs.

Systems that increase the legibility of reference acts provide one pathway to reducing this referential gap. FIESTA supports embodied deixis by rendering tracked head/hand avatars aligned to users' positions, enabling pointing and conveying gaze direction, and by making interaction state visible (e.g., shared selections and pointers), improving workspace awareness~\cite{Lee2021SharedSurfacesSpaces}. Evaluations of such environments should therefore test not only whether teams finish faster, but whether referential overhead decreases (e.g., fewer repeated pointing episodes or verbal disambiguations), linking performance gains to reduced coordination cost.

Hybrid large-display designs emphasize a complementary trade-off: preserving shared context while reducing mutual interference. Reipschl{\"a}ger et al.\ augment a shared wall with \emph{personal} AR overlays so individuals can access additional views without cluttering or obstructing the shared surface~\cite{Reipschlaeger2021PersonalAR}. This motivates measuring how well systems balance shared reference with individual exploration, including perceived coordination quality, distraction, and occlusion. Overall, large-display evaluation should treat shared-reference maintenance as a first-class cost function, not a secondary usability concern, and connect outcomes to collaboration-centered task success (Section~\ref{sec:coordination-collaboration}).

\subsubsection{Immersive Environments (VR and AR) Evaluation}
\label{sec:eval-immersive}
% \textit{Immersive evaluation needs to quantify a tradeoff. Stereoscopic depth can make dense 3D structures more legible, but embodied navigation and display physiology introduce new costs that can dominate time and comfort.}

A useful way to frame evaluation in immersive environments is to separate two competing effects. The first is a \emph{stereo dividend}, a measurable perceptual benefit from true binocular disparity, head coupled motion parallax, and embodied scale. The second is a \emph{navigation tax}, the time, workload, and fatigue incurred by moving through and operating in 3D rather than manipulating a view with a mouse.

\paragraph{The stereo dividend: monoscopic 3D is not the same as stereoscopic 3D.}
Monoscopic 3D, typical of a desktop 3D view, renders a 3D layout but shows the same image to both eyes, depth is inferred from perspective, shading, and motion. Stereoscopic 3D, typical of VR and many AR head mounted displays, renders distinct left and right eye images, enabling binocular disparity and stronger occlusion ordering. In graph analytics tasks, Greffard et al.\ compared 2D, monoscopic 3D, and stereoscopic 3D, and found that the stereoscopic condition produced significantly higher accuracy than both alternatives for community detection, even though 2D yielded lower response times \cite{Greffard2014BeyondMonoscopic3D}. Ware and Mitchell report a complementary result for path tracing in node link diagrams, with stereo and motion depth cues allowing users to trace short paths in graphs containing hundreds to a thousand nodes with low error, an order of magnitude larger than comparable 2D viewing \cite{Ware2008Graphs3D}. For point cloud tasks, which are closer to biomedical embeddings than node link graphs, Kraus et al.\ show that increased immersion can be a substantial benefit for cluster identification in 3D data \cite{Kraus2020ImmersionClusterIdentification}. Taken together, these findings motivate an evaluation stance where VR and AR are not treated as aesthetic upgrades, they are tested as perception altering interfaces that can change error rates on tasks where occlusion and depth are core to the problem.

\paragraph{The navigation tax: perception improves, locomotion still costs.}
The stereo dividend does not come for free, because immersive systems shift some of the analytical burden from purely visual decoding to viewpoint management. Yang et al.\ explicitly analyze embodied navigation for immersive abstract visualization, decomposing navigation into travel and wayfinding costs, and showing that navigation techniques such as zooming and overview plus detail can be more effective than locomotion alone for 3D scatterplots, especially in seated VR. Their discussion also highlights practical costs that matter for evaluation, larger tracked spaces can support more physical navigation, but can also induce significant fatigue, and switching between physical movement and pointer based teleportation can introduce context switching overhead \cite{Yang2021EmbodiedNavigation}. For evaluation methodology, this implies that time and error are necessary but incomplete, immersive studies should also report navigation specific metrics (travel distance, number of viewpoint changes, reorientation events) and subjective workload, since these capture the operational cost of making use of depth.

\paragraph{Physiology and artifacts: the ugly side of stereo.}
Even when stereoscopy improves accuracy, it can also produce discomfort and visual artifacts. McIntire and Liggett summarize how vergence accommodation mismatch, crosstalk, and related display limitations contribute to eyestrain and fatigue in stereoscopic viewing, and they note that a nontrivial fraction of users can experience discomfort \cite{Sedlmair2014GoodBadUgly}. This is not an argument against immersive analytics, but it is a strong argument for reporting comfort outcomes alongside performance outcomes, including simulator sickness measures, dropouts, breaks, and hardware parameters that affect stereo quality.

\paragraph{Strategic conclusion: 3D is here to stay, so evaluate it honestly.}
Brath’s position, that 3D infovis is here to stay and the field should focus on where it is useful and how to handle its limitations, provides a pragmatic endpoint for evaluation framing \cite{Brath2014InfoVisHereToStay}. For life science visual analytics, many targets are intrinsically spatial, from molecular assemblies to tissue scale morphology and anatomical connectomes, so depth perception is often a necessary ingredient for untangling dense configurations. The evaluation agenda is therefore not to claim that VR is universally superior, but to quantify when the stereo dividend outweighs the navigation and physiological taxes, and to use those measurements to justify hybrid workflows that move fluidly between immersive and non immersive tools.
\subsection{Evaluation of AI-Assistance Modes}
\label{sec:eval-ai-modes}
% \textit{Discuss how each AI assistance type is evaluated in the context of visual analytics.}

Section~\ref{sec:eval-across-modalities} showed that visualization modality changes task load and cognitive strategy. Here we shift from \emph{where} analysis happens to \emph{how} computational intelligence reshapes the analytic loop. Unlike evaluating a visualization technique in isolation, evaluating assistance must account for how it changes what users see, which operations are executed, which explanations are offered, and which hypotheses become salient. In life-science contexts, where outcomes can affect downstream experimental decisions, evaluation should therefore address not only performance and usability, but also reliability, interpretive bias, and users' ability to supervise and correct the system~\cite{Isenberg2013ReviewEvaluatingVis}.

A practical baseline is to treat assistance as an intervention and evaluate it with ablations: compare the same interface with and without the assistance component, and compare alternative assistance strategies under the same task conditions. Dependent measures should match the supported task category (Section~\ref{sec:task-categories}): orientation loss and reorientation effort for Navigation and Multiscale Orientation (Section~\ref{sec:automated-view-switching}); verification stability for Comparison and Differentiation (Section~\ref{sec:comparison-differentiation}); target acquisition and recovery cost for Selection/Filtering/Precision interaction (Section~\ref{sec:selection-filtering-precision}); evidence articulation, provenance tracking, and error detection for Sensemaking and Hypothesis Development (Section~\ref{sec:sensemaking-hypothesis}); and common ground and referential clarity for Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}).

Across assistance types, three cross-cutting questions repeatedly determine whether AI helps or silently harms: \emph{effectiveness} (does it improve outcomes or reduce interaction burden at realistic scales?), \emph{process quality} (can users understand, reproduce, and audit what happened?), and \emph{control and calibration} (can users intervene appropriately without overreliance or automation bias?). The subsections below organize evaluation practices by the four assistance modes used throughout the STAR: algorithmic, adaptive, conversational/agentic, and immersive-AI assistance, highlighting mode-specific risks such as stability and reproducibility for adaptation, error propagation and controllability for conversation, and comfort/fatigue for XR-embedded assistance.

\subsubsection{Algorithmic Assistance}
 %Metrics for algorithmic techniques (clustering quality, layout metrics, etc.) and note that these often ignore human-in-the-loop impact.
\label{sec:eval-alg-assistance}

 Evaluation of algorithmic assistance in life-science visual analytics must account for the fact that time, complexity, and latency are usability features, not merely performance concerns. As biological datasets grow in size and density, algorithmic choices increasingly determine which analytical tasks (Section~\ref{sec:task-categories}) are feasible at all. We therefore frame evaluation around three tightly coupled axes: computational scalability, representational fidelity, and auditability/provenance.

\paragraph{Computational scalability and interaction latency}
    
The first evaluation axis concerns how algorithmic methods scale with data size and how this scaling impacts interactive responsiveness. Classical force-directed graph layouts provide a useful baseline: methods such as ForceAtlas2 remain effective for moderate graph sizes but exhibit quadratic or worse behavior as node and edge counts grow, leading to unacceptable latency and interaction breakdowns in dense biological networks \cite{Jacomy2014ForceAtlas2}. Work on faster force-directed graph drawing using well-separated pair decomposition (WSPD) makes this limitation explicit by demonstrating how algorithmic complexity, rather than rendering alone, becomes the dominant bottleneck at scale \cite{Gansner2015WSPD}.
Recent systems emphasize approximation, binning, and density-based strategies as necessary responses to this compute gap. scSVA, for example, demonstrates that interactive exploration of single-cell RNA-seq data at billion-cell scale is only possible by aggregating observations into density summaries rather than rendering individual points, effectively trading raw detail for responsiveness \cite{Feng2021scSVA}. Similarly, approximate nearest-neighbor graph construction enables large-scale biological similarity analysis by replacing exact neighborhood computation with scalable approximations, making interactive workflows feasible where exact methods would fail \cite{Xu2023ANNBio}.
From a task perspective, scalability failures disproportionately damage Navigation and Multiscale Orientation and Comparison and Differentiation tasks (Section \ref{sec:task-categories}: when interaction latency exceeds cognitive tolerance, users can no longer maintain spatial or conceptual context while exploring structure.
    
\paragraph{Representational fidelity under complexity management}
The second axis evaluates what algorithmic assistance preserves, removes, or distorts when managing complexity. Decluttering techniques such as edge bundling illustrate the long-standing tension between readability and computational cost: while bundling can reduce visual clutter in dense graphs, it introduces additional computation and may obscure individual paths, limiting its effectiveness as graph size grows \cite{Holten2006EdgeBundling}.
More recent work explicitly treats complexity management as a design space rather than an afterthought. CMGV provides a unified framework that categorizes complexity-management strategies—aggregation, filtering, abstraction, and approximation—and emphasizes that each strategy entails specific representational trade-offs \cite{Keller2023CMGV}. These trade-offs must be evaluated relative to analytic intent: what is gained in overview may be lost in precision, and vice versa.
Practical desktop systems further ground these concerns. Graphia demonstrates how performance-aware design choices shape interaction expectations in real analytical workflows, balancing graph size, layout recomputation, and responsiveness to support iterative exploration of high-dimensional biological data \cite{Freeman2021Graphia}. In these systems, representational fidelity is inseparable from performance constraints: what is shown is determined by what can be computed fast enough to remain interactive.
    % \subsubsection{Algorithmic Assistance}

\paragraph{Procedural provenance is part of evaluation, not an afterthought.}
Algorithmic assistance is evaluated not only by mathematical fidelity (e.g., stability, topology preservation, neighborhood recall) but also by procedural legitimacy. Even a visually compelling embedding or projection is not safe to treat as analytic ground truth if authorship, reproducibility, or provenance is in doubt. The retraction of Panoramic Manifold Projection (Panoramap) on authorship and provenance grounds is a useful cautionary example. It underscores that verification is both mathematical and procedural, and that evaluation reports should include reproducibility artifacts, implementation traceability, and clear provenance statements, especially when an algorithm becomes a widely reused preprocessing step \cite{ijms2024retraction,wang2022panoramap_retracted}.

\paragraph{Auditability, provenance, and system-level pressure}
The third axis concerns whether users can understand and reason about what algorithmic assistance has done. As systems increasingly rely on approximation, aggregation, and precomputation, evaluation must consider whether analysts can trace how results were produced and assess their reliability.
System-level studies make this pressure visible. Interactive Graph Visualization and Teaming Recommendation in an Interdisciplinary Project’s Talent Knowledge Graph illustrates how latency and scaling constraints directly affect collaborative analysis, forcing systems to prioritize responsiveness over completeness in order to remain usable \cite{Zhang2024TalentKG}. Similarly, Uchimata highlights how web-based visualization of large 3D genome structures must negotiate strict performance budgets, demonstrating that deployment context (desktop vs. web) is itself an evaluation factor that shapes algorithmic choices and analytic affordances \cite{Kobayashi2023Uchimata}.
Across these examples, auditability is not only about algorithm transparency but also about exposing limits: users must be able to recognize when approximation, aggregation, or pruning has altered the analytical substrate.


Overall, these works show that evaluation of algorithmic assistance cannot be reduced to accuracy or visual quality alone. Computational scalability, representational fidelity, and auditability/provenance form an inseparable triad that determines whether algorithmic assistance genuinely supports life-science visual analytics or silently constrains it. As dataset size increases, failures along any of these axes first undermine navigation and comparison tasks, reinforcing the need to treat complexity management as a first-class evaluation concern rather than an implementation detail
 
\subsubsection{Adaptive Assistance}

Evaluating adaptive assistance requires separating system-level performance from its downstream effects on analysis behavior and user experience.
\emph{Performance metrics} capture the efficiency and fidelity of the adaptive machinery itself, including interaction latency, computational overhead, and prediction accuracy of user models such as next-interaction or intent prediction and exploration-bias detection.
\emph{Behavioral outcomes} assess how adaptation reshapes analytic activity, using measures such as coverage and diversity of the explored space, balance across attributes or hypotheses, and the system’s ability to detect, and ideally, mitigate rather than reinforce, exploration bias~\cite{Ha2022UserModeling}.
\emph{Human factors} evaluation addresses experiential consequences of mixed-initiative guidance, including trust, perceived autonomy and controllability, and cognitive load, reflecting concerns that adaptive systems may reduce burden while simultaneously steering analysis.
Finally, evaluation must be \emph{audience-dependent}: expert analysts and public or novice users respond differently to guidance, with experts often prioritizing transparency and override, and non-experts benefiting more from prescriptive support.
Dual expert/end-user evaluation frameworks demonstrate that adaptive guidance should therefore be assessed separately across user populations, using task-appropriate success criteria rather than a single aggregate metric~\cite{Steichen2017DualEvaluation}.
Adaptive systems should communicate a balanced view of their impact by reporting both benefits (such as efficiency gains or reduced cognitive load) and harms (such as steering effects or reduced diversity of exploration). For each side, system designers should provide at least one explicit, well-defined metric to support these claims.

\subsubsection{Evaluation of Conversational and Agentic Assistance}
% \subsubsection{Conversational Assistance}
\label{sec:conversational-assistance}
% \textit{ How to evaluate LLM-driven analytics (checking for factual correctness, task success rates, user trust and understanding), noting the challenge of scientific accuracy.}

Evaluating conversational and agentic analytics systems requires a different lens than evaluating conventional visualization tools. In life-science settings, analytic errors rarely remain ``in the interface'': inappropriate filtering, comparisons, or analytic paths can misdirect interpretation and downstream experimental choices even when intermediate outputs look plausible. These risks make process awareness and provenance central to trustworthy use, tying evaluation directly to Selection/Filtering/Precision interaction, Comparison and Differentiation, and Sensemaking and Hypothesis Development (Sections~\ref{sec:selection-filtering-precision}, \ref{sec:comparison-differentiation}, and~\ref{sec:sensemaking-hypothesis}; see also Section~\ref{sec:task-categories}).

Early evaluations of natural language interfaces (NLIs) for visualization largely emphasized output correctness for isolated requests (e.g., generating a chart or applying a filter)~\cite{Wang2024DomainBridge}. As discussed in Section~\ref{sec:agentic-orchestration}, newer systems increasingly plan and execute multi-step analyses on the user's behalf~\cite{Jia2024LightVA,Kim2024PhenoAssistant}. In this setting, final-result correctness is not sufficient: evaluation must assess whether intermediate steps are reasonable, align with user intent, and remain steerable when the system takes a wrong turn.

A core requirement is reasoning transparency. DeepVIS shows how exposing intermediate decisions, such as how a question was interpreted, which data were selected, and why a visualization was chosen, enables users to inspect and verify system behavior~\cite{DeepVIS2023}. For scientific analysis, such visibility supports auditability: without it, users cannot distinguish meaningful biological structure from artifacts of assumptions, transformations, or encodings, nor intervene before errors propagate.

Human-in-the-loop designs further clarify what ``success'' should mean for agentic assistance. Wang et al.\ show that reliable use of LLMs for life-science literature analysis depends on structuring human validation at key abstraction points, translating specialized terminology into representations that experts can review and correct~\cite{Wang2024DomainBridge}. This implies evaluation criteria centered on faithful translation, interpretability, and correctable intermediate representations, not autonomy alone.

Agentic systems also introduce failure modes that are subtle by nature: selecting inappropriate subsets, applying unsuitable methods, or making premature recommendations can steer users toward flawed interpretations without obvious local errors~\cite{Chen2024ProactiveVA}. Effective evaluation should therefore probe detectability and recoverability: whether users can recognize problems, understand why they occurred, and redirect analysis, capabilities that map to Sensemaking/Hypothesis work and to corrective selection and comparison cycles (Sections~\ref{sec:sensemaking-hypothesis}, \ref{sec:selection-filtering-precision}, and~\ref{sec:comparison-differentiation}).

Finally, interaction context matters. In large-display and immersive settings (Sections~\ref{sec:large-displays} and~\ref{sec:spatial-graph-reasoning}), analysis is often supervised collaboratively; evaluation should therefore include collective oversight outcomes such as shared understanding, timely intervention, and maintenance of common ground, not only individual task performance~\cite{Leon2025TalkToTheWall,Song2025EmbodiedNLI,Jia2025VOICE}. Overall, evaluating conversational and agentic assistance should shift from outcome-only metrics toward process-focused assessment that tests transparency, controllability, and scientific reliability under realistic workflows.

\subsubsection{Immersive-AI Assistance}
\label{sec:eval-immersive-ai-assistance}
% \textit{How immersive intelligent features are evaluated (navigation efficiency, selection accuracy, user comfort), noting that this area is nascent with few established protocols.}

Evaluating immersive AI assistance is challenging because the assistance is rarely a detachable component. In XR, ``intelligence'' is often embedded directly into viewpoint control, selection mechanics, occlusion management, and multimodal input fusion, so the evaluation must capture both the analytic outcome and the embodied cost of reaching it. In other words, immersive systems can deliver a perceptual dividend through depth and scale, but they also impose operational taxes through locomotion, disorientation, and mid air interaction fatigue. Immersive AI assistance should therefore be evaluated as a \emph{performance and comfort mediator}, it is successful when it reduces navigation burden, stabilizes interaction, and guides attention without masking uncertainty or taking control away from the analyst.

\paragraph{Navigation efficiency and viewpoint management.}
Navigation is the dominant hidden cost in immersive analytics, especially for abstract or semi abstract biological views (embeddings, similarity spaces, networks). Yang et al.\ decompose embodied navigation into travel and wayfinding costs, and show that interaction designs that reduce unnecessary locomotion, for example zooming and overview plus detail, can outperform locomotion alone in 3D scatterplot analysis \cite{Yang2021EmbodiedNavigation}. This motivates navigation focused evaluation metrics that go beyond time and error, including travel distance, number of viewpoint changes, reorientation events, collisions or near collisions, and the frequency of context rebuilding after a viewpoint shift. When navigation becomes AI mediated, these metrics must be paired with measures of \emph{appropriateness}, for example whether automatic transitions match the user’s analytic intent. Ng et al.\ provide a useful baseline by comparing exocentric and egocentric frames for biomedical cohort analysis in VR, showing that view framing changes both speed and perceived usability \cite{Ng2024ExoEgo}. For systems that generate or recommend routes through dense geometry, such as Nanotilus, evaluation can additionally include path quality measures, for example whether the camera route avoids occluders and maintains a stable mental map, and whether users can interrupt or deviate without losing orientation \cite{Alharbi2023Nanotilus}.

\paragraph{Selection and manipulation accuracy under motor and physics constraints.}
A second evaluation axis concerns whether immersive AI assistance improves precision in dense biological scenes where standard controller based ray casting becomes jittery and exhausting. Dai et al.\ evaluate this problem through Magic Portals, a focus plus context technique that brings distant regions into comfortable reach, optionally with haptic confirmation, and can be assessed with target acquisition accuracy, selection time, correction actions, and self reported workload and arm fatigue, often called the gorilla arm effect, which is the strain that builds when users hold their arms elevated for prolonged mid air interaction \cite{Dai2025MagicPortals}. Molecular interaction tasks highlight a related idea, constraints matter as much as freedom. In immersive docking, Mishra et al.\ show that human guided manipulation within physically meaningful constraints can produce useful interaction trajectories that feed subsequent simulation, suggesting evaluation should consider both user performance and downstream scientific utility, for example whether assisted interaction produces plausible, reproducible docking or unbinding pathways, not only whether the user could ``grab and move'' objects quickly \cite{Mishra2024DockingVR}.

\paragraph{Attention guidance, cognitive load, and user comfort.}
Finally, immersive assistance often operates as attention management in a 360 degree workspace, where relevant targets can be out of view and where spatial cues compete with task cognition. Doerr et al.\ empirically evaluate highlighting techniques for situated brushing and linking, illustrating how attention cues can improve findability and reduce search effort, but can also become clutter when selections grow, which suggests that evaluation should explicitly track both benefits (find time, misses, reacquisition time) and side effects (visual overload, distraction, perceived loss of agency) \cite{Doerr2024SituatedHighlighting}. Related training evidence reinforces that guidance can change user strategies in lasting ways. In SONAR interpretation training, an egocentric conformal overlay improved speed and accuracy, but it also raised concerns about over reliance once assistance is removed, a pattern that immersive AI evaluation should measure directly through retention and transfer tests \cite{Salamon2025TrainingSONAR}. Across all immersive AI studies, performance results should be reported alongside comfort outcomes, including simulator sickness measures, breaks, dropouts, and hardware parameters that affect stereo quality, because an assistance technique that improves accuracy is not viable if it increases fatigue or discomfort to the point that users avoid sustained use.

Overall, evaluation practice for immersive AI assistance is still nascent. The strongest studies treat assistance as an intervention, compare it against non assisted baselines, log multimodal interaction traces, and report navigation and comfort measures in addition to task accuracy. However, consistent protocols and benchmarks remain rare, which limits comparability across systems and makes it difficult to generalize results beyond a single interface or dataset.

\subsection{Gaps in Evaluation}
\label{sec:gaps-evaluation}
% \textit{Major unmet evaluation needs: missing benchmark tasks and datasets, lack of cross modality studies, and insufficient methods for combined AI plus immersive interaction evaluation.}

The literature exposes three recurring evaluation gaps. First, there is a lack of shared standards and benchmark tasks for multimodal, AI-assisted visual analytics, particularly in life-science settings where realistic data complexity is essential. Studies often rely on bespoke datasets, tasks, and logging, limiting comparability and reproducibility. The unified task categories in Section~\ref{sec:task-categories} provide a basis for benchmark design, but the field still needs reference datasets, task scripts, and reporting templates that cover multimodal input (gaze, gesture, speech, controllers), mixed-initiative behavior, and long-running analytic sessions.

Second, cross-modality comparisons remain rare. Many papers evaluate a single modality in isolation, leaving the practical question unanswered: when should a workflow remain on the desktop, move to a large display, or justify immersion? More controlled studies should run the \emph{same} tasks on the \emph{same} data across 2D, pseudo-3D, large displays, and VR/AR, reporting both task outcomes and operational costs such as navigation effort, fatigue, and coordination overhead.

Third, the community lacks robust methods for evaluating coupled AI and immersive interaction. When assistance is adaptive, intent-inferred, or viewpoint-controlling, the system behaves as a dynamic policy rather than a static tool; time and error alone cannot capture steering effects, failure detectability, recovery, or provenance preservation. Addressing this requires evaluation frameworks that combine ablations (assistance on/off), process measures (interaction traces, decision points, provenance awareness), and comfort measures, and that test both immediate performance and longer-term calibration (e.g., overreliance and transfer). Overall, these gaps motivate end-to-end evaluation approaches that treat XR analytics as mixed-initiative scientific workflows rather than isolated interface techniques.

\section{Research Challenges and Opportunities}
This survey shows that, despite substantial progress in biological visual analytics, persistent challenges remain across analytical tasks, visualization modalities, AI assistance, and their integration. These are not isolated implementation gaps: they reflect recurring tensions among scalability, interpretability, cognitive load, and scientific trust. Below, we synthesize research challenges grounded in the surveyed literature and highlight opportunity areas for future work.

\subsection{Task-Level Challenges}
A central task-level challenge is determining when AI assistance strengthens scientific insight and when it risks misleading users. Many systems accelerate early-stage exploration (e.g., surfacing candidate patterns or neighborhoods), yet can undermine later-stage Sensemaking and Hypothesis Development when automated outputs are accepted uncritically (Section~\ref{sec:sensemaking-hypothesis}). Early work in biological network visualization already warned that visually compelling structure can mask uncertainty and analytical assumptions, encouraging overinterpretation in dense networks~\cite{Suderman2007}. This risk extends to modern abstraction, embedding, and summarization pipelines that shape what users attend to during Comparison and Differentiation (Section~\ref{sec:comparison-differentiation}).

This concern is amplified when assistance introduces learned structure. Hierarchical and supervised approaches such as Haisu provide embeddings aligned with biological organization, but users still need to understand what is emphasized, suppressed, or distorted by the model and how conclusions change under alternative views or parameterizations~\cite{vanhorn2022haisu}. Without explicit support for verification, uncertainty, and provenance, assistance can bias exploration toward dominant patterns while hiding subtle but biologically meaningful signals.

More broadly, task-grounded evaluation remains underdeveloped. Many systems report performance or clarity gains, but provide limited evidence that assistance improves reasoning quality, error detection, or hypothesis robustness over time, especially in end-to-end scientific workflows rather than isolated tasks (Sections~\ref{sec:eval-ai-modes} and~\ref{sec:gaps-evaluation})~\cite{Ehlers2025}.

\subsection{Modality-Level Challenges}
Visualization modality fundamentally changes which tasks are cognitively cheap versus expensive (Section~\ref{sec:visualization-modalities}). Desktop 2D environments dominate biological network analysis due to precision, reproducibility, and toolchain integration. Cytoscape remains a canonical example~\cite{Shannon2003}, supporting fast Selection/Filtering/Precision interaction (Section~\ref{sec:selection-filtering-precision}), with a variety of third-party modules and extensive documentation. At scale, however, 2D workflows encounter severe clutter and occlusion, motivating alternative encodings such as BioFabric, which replaces node--link geometry with structured linear layouts to reduce overlap~\cite{Longabaugh2012}.

Immersive environments promise relief by leveraging spatial cognition and embodied navigation (Section~\ref{sec:immersive-environments}). Systems such as VRNetzer suggest that large biological networks can become traversable in VR when spatial interaction is used to manage density~\cite{Pirch2021}. Yet immersion introduces its own costs: fatigue, navigation overhead, and increased cognitive load for dense or abstract data---and empirical evidence indicates that benefits are task-dependent rather than universal~\cite{Pavlopoulos2017,Ehlers2025}. A core open problem is therefore prescriptive guidance: which task categories benefit from immersion (e.g., Navigation and Multiscale Orientation versus precise selection), which are better served on 2D, and how to design hybrid workflows that allow transitions across modalities without losing analytic context (Section~\ref{sec:cross-modal-synergies}).

\subsection{AI-Level Challenges}
At the AI level, trust, interpretability, and robustness remain foundational challenges. As systems incorporate machine learning for clustering, embedding, recommendation, and explanation, users must be able to reason about how models shape what they see and conclude. Prior warnings about ``false certainty'' in network visualization apply directly here: when algorithmic assumptions are hidden, systems can look authoritative while remaining fragile~\cite{Suderman2007}. Even when alignment improves, as with supervised or hierarchical embeddings such as Haisu, the encoded domain assumptions may not transfer across datasets or experimental contexts~\cite{vanhorn2022haisu}.

These issues intensify in mixed-initiative settings where assistance becomes adaptive or conversational (Sections~\ref{sec:agentic-orchestration} and~\ref{sec:conversational-assistance}). Persuasive explanations, proactive suggestions, and workflow-level orchestration can reduce interaction burden, but also increase the risk of over-reliance if uncertainty, bias, and limitations are not made salient. A recurring opportunity is to treat explainability, provenance, and calibrated trust as first-class design goals, not after-the-fact evaluation criteria~\cite{Ehlers2025}.

\subsection{Integration Challenges}
The most consequential challenges arise at the intersection of modality and assistance, where multiple representations, interaction techniques, and computational processes must coexist (Section~\ref{sec:cross-modal-synergies}). In immersive settings such as VRNetzer, users navigate spatially while engaging with algorithmically structured representations; adding adaptive guidance or automated recommendations raises unresolved design questions about shared control, conflict resolution between system suggestions and user intent, and how to prevent assistance from becoming intrusive or misleading during Navigation and Selection tasks (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision}). When multiple AI modes operate simultaneously (speech, gesture, gaze, controllers, plus algorithmic and conversational outputs) overlapping interventions can fragment attention and increase cognitive load unless coordination and override mechanisms are explicit~\cite{Pirch2021,Ehlers2025}.

A further integration challenge is workflow continuity across tools and devices. Today, analysts often move between ecosystems such as Cytoscape for annotation and filtering, BioFabric for alternative structural views, and immersive tools for large-scale exploration, with limited support for synchronizing state, provenance, and interaction history across transitions~\cite{Shannon2003,Longabaugh2012,Pirch2021}. As recent surveys note, this forces users to repeatedly reconstruct context, undermining Sensemaking and reproducibility~\cite{Ehlers2025}. Developing infrastructures that preserve analytical state across modalities, and evaluating them as end-to-end scientific workflows (Section~\ref{sec:eval-landscape}), remains a key opportunity for future research.


\subsection{Future Directions}
 %Highlight promising research directions.
Overall, these challenges suggest that future progress will depend less on isolated advances in algorithms or displays and more on integrated, task-aware, and diagnostic systems. Promising directions include designing AI assistance that foregrounds uncertainty and alternatives, developing modality-aware workflows that align representation with task demands, and building infrastructures that support seamless transitions across analytical environments.
Addressing the hairball problem in the life sciences ultimately requires not only making complex data visible, but ensuring that what is seen supports trustworthy, interpretable, and scientifically grounded reasoning.
 
\subsubsection{Multimodal LLMs in Immersive Analytics}
% \textit{ AI models that can simultaneously analyze text, images, graphs, and spatial data to enable richer interactive analysis in VR/AR.}

As visual analytics expands into room-scale VR/AR and wall-scale collaborative settings, interaction becomes spatially grounded: users coordinate intent through embodied actions (e.g., pointing) and deictic language that presupposes a shared layout. This is particularly consequential for life-science graph and structure exploration, where spatial organization carries interpretive meaning (e.g., separation, proximity, adjacency) and task execution frequently couples Navigation and Multiscale Orientation with Selection/Filtering/Precision interaction (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision}). For conversational systems, this implies that intent resolution must be grounded in the live spatial state rather than treated as text-to-command translation (Section~\ref{sec:conversational-assistance}).

Empirical evidence shows that deictic (spatially referential) language is dominant in immersive analysis. Song et al.\ report that users systematically combine utterances with embodiment cues (e.g., spatial deixis such as ``these'' or ``on the left of me''), and that speech uncertainty (semantic entropy) varies by task and phase. They argue that immersive NLIs should manage this variability with uncertainty-aware interface strategies and mechanisms that leverage spatial cues for disambiguation~\cite{Song2025EmbodiedNLI}. Complementary wall-scale findings show that speech is often preferred for global actions while touch supports localized operations, and that speech also functions as a coordination channel that supports shared awareness~\cite{Leon2025TalkToTheWall}. Together, these results suggest that language, spatial context, and interaction state should be treated as co-equal inputs to intent inference, especially for Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}).

System evidence further suggests that conversational control can reduce the navigation tax when interacting with complex 3D scientific content. \emph{VOICE} illustrates this direction for molecular exploration by translating high-level instructions into coordinated visual and verbal outputs over a 3D molecular model using LLM-based processing~\cite{Jia2025VOICE}. While VOICE is not a general solution for graph analytics, it exemplifies a broader opportunity: users express conceptual goals (what to inspect and why) while the system manages viewpoint and representation changes (how to reveal it), reallocating effort from camera control to interpretation (Sections~\ref{sec:automated-view-switching} and~\ref{sec:sensemaking-hypothesis}).

For graph-structured biological data, spatially grounded requests often depend simultaneously on \emph{what} is referenced and \emph{where} it sits in the current layout (e.g., a module ``over there'' or a neighborhood ``around this region''). Supporting such interaction requires multimodal conversational systems that (i) resolve deixis against live spatial state, (ii) surface disambiguation when uncertainty is high, and (iii) preserve user agency by making intermediate interpretations legible~\cite{Song2025EmbodiedNLI,Leon2025TalkToTheWall}. The opportunity is therefore not ``voice in 3D,'' but integrated intent-resolution loops in which conversational assistance is continuously grounded in spatial context and reconciled with interactive state.


\subsubsection{Spatially Aware Graph Reasoning}
% \textit{ Intelligent agents that understand 3D spatial structure of networks (occlusion, topology) and can autonomously adjust layouts or suggest navigation in immersive environments.}
\label{sec:spatial-graph-reasoning}

As visual analytics moves into room-scale VR/AR and wall-scale collaborative settings, interaction shifts from menu-driven commands toward reasoning with spatial context. Users coordinate intent through speech, pointing, and shared reference, which is especially consequential for life-science graphs and structures where spatial organization encodes meaning (e.g., separation, proximity, adjacency). In practice, these interactions couple Navigation and Multiscale Orientation with Selection/Filtering/Precision interaction (Sections~\ref{sec:automated-view-switching} and~\ref{sec:selection-filtering-precision}; see also Section~\ref{sec:task-categories}), and place new demands on how systems maintain common ground in collaboration (Section~\ref{sec:coordination-collaboration}).

Empirical studies show that deictic language is a dominant strategy in immersive analysis rather than an edge case. Song et al.\ report that users systematically combine utterances with embodied cues (e.g., pointing and relative position: ``these,'' ``on the left of me''), often omitting explicit identifiers when shared spatial context is available. They also show that speech uncertainty varies by task and phase, motivating uncertainty-aware interfaces that leverage spatial cues for disambiguation~\cite{Song2025EmbodiedNLI}. Complementary wall-scale results indicate that speech is often preferred for global state changes while touch supports localized operations, and that speech acts as a coordination channel supporting awareness among collaborators~\cite{Leon2025TalkToTheWall}. When systems fail to resolve deixis reliably, users are forced into over-specified commands that disrupt analytic flow and increase coordination overhead.

System evidence further suggests that conversational interaction can reduce the navigation tax for complex 3D scientific content. \emph{VOICE} demonstrates this principle for molecular exploration by allowing users to express high-level requests (what to inspect and why) while the system manages camera movement, viewpoint changes, and explanatory output~\cite{Jia2025VOICE}. While VOICE does not solve general graph analytics, it illustrates a broader opportunity for spatially aware reasoning: reallocating effort from low-level viewpoint control to interpretation and hypothesis work (Section~\ref{sec:sensemaking-hypothesis}).

For graph-structured biological data, spatial language enables compound requests whose meaning depends jointly on \emph{what} is referenced and \emph{where} it appears in the current layout (e.g., a module ``over there'' or a neighborhood ``around this region''). Supporting such interaction requires systems that bind language to live spatial state, surface disambiguation when uncertainty is high, and make intermediate interpretations legible so users can correct misunderstandings~\cite{Song2025EmbodiedNLI,Leon2025TalkToTheWall}. From this perspective, spatially aware graph reasoning is not ``voice commands in 3D,'' but an intent-resolution loop that continuously aligns language, gesture, space, and system state, a prerequisite for agentic orchestration that remains steerable as systems take on more procedural responsibility (Section~\ref{sec:agentic-orchestration}).

\subsubsection{Cross-Platform Visual Analytics Ecosystems}
% \textit{Unified tools that connect 2D desktop, large displays, and XR environments in one workflow, allowing analysts to seamlessly move between modalities with synchronized AI support.}
\label{sec:cross-platform-ecosystems}

A consistent theme in immersive analytics is that no single platform supports the full range of activities in real scientific workflows. XR can be advantageous for spatial reasoning and embodied sensemaking, while 2D desktops remain superior for scripting, statistical analysis, and precise parameter control, key for Selection/Filtering/Precision interaction (Section~\ref{sec:selection-filtering-precision}). As a result, immersive analytics is increasingly framed as a complementary component in cross-platform ecosystems that preserve analytic continuity across devices (Sections~\ref{sec:cross-modal-synergies} and~\ref{sec:modality-task-load}).

\paragraph{The right tool for the right task.}
Hybrid-dimensional visualization studies provide empirical grounding for this division of labor: analysts naturally alternate between 2D and 3D representations depending on task demands~\cite{SommerHybridDimVis}. Rather than forcing all work into one modality, effective ecosystems keep abstract operations and reproducible configuration in 2D while invoking immersion selectively for spatial Navigation and Multiscale Orientation and spatially grounded comparison (Sections~\ref{sec:automated-view-switching} and~\ref{sec:comparison-differentiation}). Collaborative systems reinforce this stance: Uplift integrates tangible and immersive tabletop interaction to support shared discussion while avoiding migration of precision-heavy or prolonged work into immersive space~\cite{Ens2021Uplift}.

\paragraph{NeuroCave and on-demand immersion.}
NeuroCave operationalizes ``late binding'' of immersion for connectome topology analysis: as a web application, it supports desktop interaction by default and allows users to enter VR on demand via an explicit mode switch, re-binding rendering to WebXR while preserving dataset, encodings, selections, and comparisons~\cite{Keiriz2017NeuroCave}. This treats immersion as an optional analytical lens, invoked for specific spatial reasoning needs and exited without breaking analytic state.

\paragraph{Operational perspectives and XROps.}
Cross-platform workflows require explicit state, dataflow, and provenance management: this is a recurrent gap in evaluation and infrastructure (Section~\ref{sec:gaps-evaluation}). XROps reframes immersive analytics as configurable pipelines (akin to DevOps/MLOps), decomposing systems into stages for ingestion, transformation, rendering, and interaction that can be composed and deployed across devices~\cite{Jeon2025XROps}. This pipeline view pushes scalability upstream: reduction steps (sampling, thresholding, ROI extraction, clustering, multi-resolution/LOD generation) become workflow nodes that stream task-relevant geometry to clients, aligning with multiresolution VR visualization principles~\cite{Kreylos2003MultiresolutionVR}. For life-science ``hairballs,'' the ecosystem goal is not only efficient rendering but producing interpretable, interactive representations that remain coherent across task transitions (Section~\ref{sec:task-categories}).

\paragraph{The browser as the operating system.}
Web-first architectures reduce deployment friction and better match mixed toolchains (scripts, notebooks, dashboards, ad hoc collaboration). MolecularWebXR argues for WebXR-based molecular visualization as a cross-device resource---joinable by link from laptops, phones, and head-mounted displays---with synchronous collaboration via shared rooms and integrated voice communication~\cite{CortesRodriguez2024MolecularWebXR}. DashSpace generalizes this approach to ubiquitous analytics: its WebXR workspace runs on desktop, handheld AR, and head-mounted VR, supports asymmetric collaboration (one immersed, another monitoring/editing from a conventional screen), and adopts a local-first document model for offline work with later synchronization~\cite{Borowski2025DashSpace}.

\paragraph{Hybrid input, not just hybrid displays.}
Ecosystems also depend on distributing interaction across devices. Tong et al.\ couple a tracked physical desk and PC interface with a room-scale VR workspace, enabling users to interleave precise 2D input with spatial organization within a single sensemaking session~\cite{Tong2025SpatialHybridUI}. Complementary designs separate overview and interaction across platforms; Popolin Neto et al.\ integrate an immersive display with mobile devices so global context remains stable while detailed inspection and interaction occur on personal screens~\cite{Neto2015IntegratingDistinctPlatforms}. These patterns directly support Sensemaking and Hypothesis Development by reducing context loss when moving between modalities (Section~\ref{sec:sensemaking-hypothesis}).

\paragraph{Infrastructure-level scalability and shared collaboration.}
Cross-platform ecosystems must also span hardware from headsets to wall-scale and gigapixel displays. The Reality Deck exemplifies a hardware-first approach: a cylindrical, 360$^\circ$ immersive display with gigapixel-scale resolution, paired with explicit level-of-detail policies (based on position and visual acuity) and out-of-core, tile-based texture management to keep only necessary regions resident in GPU memory~\cite{Papadopoulos2015RealityDeck}. Finally, collaboration should be a first-class architectural requirement: FIESTA (``Shared Surfaces and Spaces'') enables teams to externalize and spatially distribute visual artifacts across shared immersive surfaces, effectively turning the room into a common analytic memory~\cite{Lee2021SharedSurfacesSpaces}. In an ecosystem framing, such ``common operational pictures'' require backend services for state synchronization, provenance, and access control so insights remain consistent across devices and support Coordination and Collaborative Reasoning (Section~\ref{sec:coordination-collaboration}) and collaboration-centered evaluation (Section~\ref{sec:eval-large-collab}).


\subsubsection{AI-Assisted Evaluation Benchmarks}
 % Development of standardized benchmark datasets and tasks (with ground-truth hypotheses, spatial cognition metrics, etc.) to evaluate AI-assisted visual analytics methods across different modalities.




% \paragraph{Forward-looking trajectory.}
A technically precise trajectory is emerging toward a closed-loop learning pipeline in which interaction logs become first-class training signals for intent/user models and guidance policies, rather than merely passive provenance~\cite{wenskovitch2019mlui,Ha2022UserModeling}.
Building on these models, learned intent inference can enable dynamic task routing across scale and abstraction. For example, the system might prompt a ``zoom out'' to cohort-level structure during population-oriented exploration, and a ``zoom in'' for local inspection when attention narrows to specific regions or entities.~\cite{Wang2024GNNIntent}.
In this framing, guidance policies evolve from static recommenders into adaptive controllers over multi-view and multi-scale systems, combining proactive insight computation with action suggestion while coordinating viewpoint transitions to preserve analytic coherence~\cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation}.
Critically, evaluation must incorporate explicit bias and autonomy constraints so that adaptation does not silently steer users or collapse exploration diversity. This defines an emerging design space with open problems in robustness across users and domains, transparency/provenance of recommendations, and principled mechanisms that preserve diversity while still reducing cognitive burden~\cite{Ha2022UserModeling,Ceneda2024HeuristicDualEvaluation}.

% \section{Conclusion}
%  Summarize how AI-assisted visual analytics can transform “hairballs” into actionable hypotheses in life sciences. Reiterate the two-dimensional framework (modalities × AI modes) as a unifying perspective, the unified task taxonomy, and the outlook for future research.
%  Emphasize the key takeaways and the importance of interdisciplinary efforts moving forward.

\section{Conclusion}
\label{sec:conclusion}

This STAR surveyed how AI-assisted visual analytics can transform dense biological ``hairballs'' into actionable hypotheses by shifting effort from manual view manipulation toward mixed-initiative workflows. A central conclusion is that progress is driven less by modality or AI in isolation than by their coupling. We therefore organized the literature with a two-dimensional framework---visualization modality (horizontal) and AI assistance mode (vertical)---and grounded the synthesis in a unified task taxonomy (Section~\ref{sec:task-categories}), enabling systems to be compared by analytic intent rather than surface features or hardware novelty.

Across modalities, recurring patterns emerge. Desktops remain the workhorse for precise, reproducible analysis, increasingly relying on algorithmic, adaptive, and conversational assistance to manage scale and reduce configuration friction. Large displays strengthen shared context but are constrained by shared-reference costs, motivating assistance for view management, linking, and personal overlays that preserve common ground. Immersive VR/AR can improve tasks where depth, occlusion, and scale matter, but introduce navigation and comfort costs---making immersive-AI assistance critical for guided navigation, occlusion control, stabilized selection, and attention support. The most promising direction is cross-platform ecosystems (Section~\ref{sec:cross-platform-ecosystems}) in which analysts move fluidly between devices while analytic state and assistance persist across boundaries (Section~\ref{sec:cross-modal-synergies}).

Looking forward, key research questions are system-level and interdisciplinary: designing modality- and task-aware assistance that is transparent, auditable, and reproducible (especially when adaptive or generative); expanding evaluation beyond time/error to include reasoning quality, provenance, trust calibration, and collaborative common ground (Sections~\ref{sec:eval-landscape} and~\ref{sec:gaps-evaluation}); and strengthening collaboration among visualization, machine learning, and life-science experts to ensure that intelligent visual analytics amplifies biological insight rather than merely accelerating interaction.


%-------------------------------------------------------------------------

\section*{Acknowledgements}
AI-assisted tools (Overleaf AI and OpenAI ChatGPT) were used for grammar correction, language polishing, limited rephrasing, and non-authoritative literature organization and summarization. All scientific content, inclusion decisions, interpretations, and conclusions were made by the authors.

%-------------------------------------------------------------------------
% bibtex
\bibliographystyle{eg-alpha-doi} 
\bibliography{BioMedVis_STAR_refs}       
\newpage

\begin{appendix}
%\appendix
\section{Methodology}
\label{app:methodology}


To ensure a comprehensive and reproducible survey of the rapidly evolving intersection between AI, visualization, and biological network analysis, we employed a semi-automated, human-in-the-loop literature review pipeline. This process leveraged custom Python scripts for data retrieval and Large Language Model (LLM) agents for semantic classification and extraction.

\subsection{Data Collection}
We queried five major academic repositories: \textbf{PubMed}, \textbf{CrossRef}, \textbf{arXiv}, \textbf{Europe PMC}, and \textbf{Semantic Scholar}. A custom Python script interfaced with the public API endpoints of these engines using a standardized set of keywords targeting the intersection of biological networks (e.g., ``genomics,'' ``connectomics,'' ``molecular dynamics'') and advanced visualization (e.g., ``immersive analytics,'' ``VR,'' ``large display'') and artificial intelligence. The initial retrieval output was aggregated into a master BibTeX file containing metadata and abstracts where available.

\subsection{LLM-Driven Classification Pipeline}
Due to the high volume of initial results, we implemented a two-stage hierarchical classification process using the OpenAI LLM API.

\paragraph{Stage 1: Assistance Mode Classification}
The master BibTeX file was processed by a sorting agent with a system prompt defining the four modes of AI assistance: \textit{Algorithmic}, \textit{Adaptive}, \textit{Conversational}, and \textit{Immersive-AI}. The agent analyzed the Title and Abstract of each entry to categorize it into one of these four modes or mark it as \textit{Off-Topic}. This stage resulted in five distinct BibTeX files.

\paragraph{Stage 2: Visualization Modality Classification}
Each of the four on-topic BibTeX files from Stage 1 was passed through a second sorting round. A separate system prompt directed the LLM to classify entries based on their display hardware and interaction environment: \textit{Desktop (2D)}, \textit{Large Display}, \textit{Virtual Reality (VR)}, \textit{Augmented/Mixed Reality (AR/XR)}, or \textit{CAVE}. This resulted in a matrix of 20 potential topic files (4 Assistance Modes $\times$ 5 Visualization Modalities) plus Off-Topic files.

\subsection{Content Extraction and Synthesis}
For papers classified as on-topic, we executed a full-text retrieval and extraction workflow:

\begin{enumerate}
    \item \textbf{Full-Text Retrieval:} Open-access manuscripts were downloaded automatically via API. Closed-access manuscripts deemed highly relevant were retrieved manually.
    \item \textbf{Semantic Extraction:} A Python script passed the full text of each paper to an OpenAI LLM agent equipped with a specific system prompt to extract structured metadata. For each paper, the agent generated a JSON object containing the Title, Authors, and five structured summary fields:
    \begin{itemize}
        \item \textbf{Core Innovation:} The primary technical contribution.
        \item \textbf{Hairball Solution:} The specific mechanism used to manage visual clutter.
        \item \textbf{Biological Utility:} The practical application in life sciences.
        \item \textbf{Key Limitation:} Constraints on scalability or usability.
        \item \textbf{STAR Integration Target:} The specific section of this report the paper belongs to.
    \end{itemize}
    \item \textbf{Relevance Scoring:} The agent assigned a numeric Relevance Score (1--5) based on the paper's alignment with the survey's goals.
\end{enumerate}

\subsection{Filtering and Final Corpus}
The classification process identified a disproportionately high volume of literature in the \textit{Desktop 2D / Algorithmic Assistance} category ($N=5,512$). To maintain a balanced scope, this specific subset was filtered to include only papers published from 2019 to present with a Relevance Score of 4 or 5. All other modalities (VR, AR, Large Display, Conversational, etc.) were included in their entirety without downsampling. Raw paper counts for each category are shown in Table \ref{tab:paper-distribution} and depicted graphically in Figure \ref{fig:paper_distribution} and symbolically in Table \ref{table:taxonomy-matrix}.

\subsection{Data and Code Availability}
To support reproducibility and further bibliometric analysis, all custom Python source code used for scraping, API interaction, and LLM-based sorting is publicly available on \href{https://github.com/iMammal/H2H-Full-STAR}{GitHub}. The complete dataset, including the raw and processed BibTeX files and the final extracted JSON corpus, has been archived on \textbf{Zenodo}.


\begin{table}[ht]
\centering
\caption{Distribution of Relevant Papers by AI Assistance Mode and Visualization Modality. (Note: Initial screening processed over 25,000 articles, with 19,465 classified as off-topic). *Original corpus of 5512 Algorithmic-Desktop papers were further filtered by date (2019-Present) and relevance score (4+ out of 5)}
\label{tab:paper-distribution}
\resizebox{\columnwidth}{!}{
\begin{tabular}{lcccccc}
\toprule
\textbf{AI Assistance} & \textbf{Desktop} & \textbf{Large Display} & \textbf{VR} & \textbf{AR/XR} & \textbf{CAVE} & \textbf{Total} \\
\midrule
Algorithmic    & 5512(97)*  & 4 & 33  & 15 & 9 & \textbf{5573(158)} \\
Adaptive       & 114 & 1 & 4   & 2  & 0 & \textbf{121} \\
Conversational & 40  & 2 & 1   & 0  & 0 & \textbf{43}  \\
Immersive-AI   & 6   & 1 & 101 & 12 & 5 & \textbf{125} \\
\midrule
\textbf{Total}            & \textbf{5672(257)} & \textbf{8} & \textbf{139} & \textbf{29} & \textbf{14} & \textbf{5959(447)} \\
\bottomrule
\end{tabular}
}
\end{table}

\end{appendix}

\end{document}
